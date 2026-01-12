#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <limits>
#include <unordered_map>

struct Edge;

struct Node {
    int id;
    std::vector<Edge*> edges;

    Node(int id_) : id(id_) {}

    static Node* newNode(int id_) {
        return new Node(id_);
    }
};

struct Edge {
    Node* to;
    double weight;

    static void addEdge(Node* from_, Node* to_, double weight_) {
        if (!from_ || !to_) return;
        Edge* e = new Edge;
        e->to = to_;
        e->weight = weight_;
        from_->edges.push_back(e);
    }

    static void addUndirectedEdge(Node* from_, Node* to_, double weight_) {
        addEdge(from_, to_, weight_);
        addEdge(to_, from_, weight_);
    }
};


inline void print(const std::vector<Node*>& graph) {
    for (auto* node : graph) {
        std::cout << "Node " << (char)node->id << ":\n";
        for (Edge* e : node->edges) {
            std::cout << "  -> " << (char)e->to->id
                << " (waga = " << e->weight << ")\n";
        }
    }
}


inline void DFS(Node* start, const std::vector<Node*>& graph) {
    if (!start) return;

    std::unordered_map<Node*, int> idx;
    idx.reserve(graph.size());
    for (int i = 0; i < (int)graph.size(); ++i) idx[graph[i]] = i;

    if (!idx.count(start)) return;

    std::vector<bool> visited(graph.size(), false);
    std::stack<Node*> s;
    s.push(start);

    while (!s.empty()) {
        Node* cur = s.top();
        s.pop();
        if (!cur) continue;

        int ci = idx[cur];
        if (visited[ci]) continue;
        visited[ci] = true;

        std::cout << (char)cur->id << " ";

        for (int i = (int)cur->edges.size() - 1; i >= 0; --i) {
            Edge* e = cur->edges[i];
            if (!e || !e->to) continue;
            if (!idx.count(e->to)) continue;

            int ni = idx[e->to];
            if (!visited[ni]) s.push(e->to);
        }
    }

    std::cout << "\n";
}

inline void BFS(Node* start, const std::vector<Node*>& graph) {
    if (!start) return;

    std::unordered_map<Node*, int> idx;
    idx.reserve(graph.size());
    for (int i = 0; i < (int)graph.size(); ++i) idx[graph[i]] = i;

    if (!idx.count(start)) return;

    std::vector<bool> visited(graph.size(), false);
    std::queue<Node*> q;

    visited[idx[start]] = true;
    q.push(start);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        if (!cur) continue;

        std::cout << (char)cur->id << " ";

        for (Edge* e : cur->edges) {
            if (!e || !e->to) continue;
            if (!idx.count(e->to)) continue;

            int ni = idx[e->to];
            if (!visited[ni]) {
                visited[ni] = true;
                q.push(e->to);
            }
        }
    }

    std::cout << "\n";
}


struct MSTEdge {
    Node* from;
    Node* to;
    double w;
};

inline double mstCost(const std::vector<MSTEdge>& mst) {
    double sum = 0.0;
    for (const auto& e : mst) sum += e.w;
    return sum;
}

inline void printMST(const std::vector<MSTEdge>& mst) {
    for (const auto& e : mst) {
        std::cout << (char)e.from->id << " - " << (char)e.to->id << " : " << e.w << "\n";
    }
    std::cout << "SUMA = " << mstCost(mst) << "\n";
}


struct DSU {
    std::vector<int> parent;
    std::vector<int> rnk;

    DSU(int n = 0) { init(n); }

    void init(int n) {
        parent.resize(n);
        rnk.assign(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int a) {
        while (parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) std::swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

inline std::vector<MSTEdge> kruskalMST(const std::vector<Node*>& graph) {
    std::vector<MSTEdge> mst;
    if (graph.empty()) return mst;

    std::unordered_map<Node*, int> idx;
    idx.reserve(graph.size());
    for (int i = 0; i < (int)graph.size(); ++i) idx[graph[i]] = i;

    struct FullEdge {
        int u, v;
        Node* from;
        Node* to;
        double w;
    };

    std::vector<FullEdge> edges;
    edges.reserve(64);

    for (auto* uNode : graph) {
        int u = idx[uNode];
        for (Edge* e : uNode->edges) {
            if (!e || !e->to) continue;
            if (!idx.count(e->to)) continue;
            int v = idx[e->to];
            if (u < v) {
                edges.push_back({ u, v, uNode, e->to, e->weight });
            }
        }
    }

    std::sort(edges.begin(), edges.end(), [](const FullEdge& a, const FullEdge& b) {
        return a.w < b.w;
        });

    DSU dsu((int)graph.size());

    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back({ e.from, e.to, e.w });
            if ((int)mst.size() == (int)graph.size() - 1) break;
        }
    }

    return mst;
}


inline std::vector<MSTEdge> primMST(const std::vector<Node*>& graph, int startIndex = 0) {
    std::vector<MSTEdge> mst;
    int n = (int)graph.size();
    if (n == 0) return mst;
    if (startIndex < 0 || startIndex >= n) startIndex = 0;

    std::unordered_map<Node*, int> idx;
    idx.reserve(graph.size());
    for (int i = 0; i < n; ++i) idx[graph[i]] = i;

    const double INF = std::numeric_limits<double>::infinity();

    std::vector<double> key(n, INF);
    std::vector<int> parent(n, -1);
    std::vector<bool> inMST(n, false);

    key[startIndex] = 0.0;

    for (int iter = 0; iter < n; ++iter) {
        int u = -1;
        double best = INF;
        for (int i = 0; i < n; ++i) {
            if (!inMST[i] && key[i] < best) {
                best = key[i];
                u = i;
            }
        }

        if (u == -1) break; 

        inMST[u] = true;

        if (parent[u] != -1) {
            mst.push_back({ graph[parent[u]], graph[u], key[u] });
        }

        Node* uNode = graph[u];
        for (Edge* e : uNode->edges) {
            if (!e || !e->to) continue;
            if (!idx.count(e->to)) continue;

            int v = idx[e->to];
            if (inMST[v]) continue;

            if (e->weight < key[v]) {
                key[v] = e->weight;
                parent[v] = u;
            }
        }
    }

    return mst;
}

#endif
