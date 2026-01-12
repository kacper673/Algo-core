#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <stack>
#include <queue>

struct Edge;

struct Node {
	int id;
	std::vector<Edge*> edges;

	Node(int id_) : id(id_) {};

	static Node* newNode(int id_) {
		return new Node(id_);
	}
};

struct Edge{
	Node* to;
	double weight;

	static void addEdge(Node* from_, Node* to_, double weight_) {
		if (from_ == nullptr || to_ == nullptr) return;
		Edge* e = new Edge;

		e->to = to_;
		e->weight = weight_;

		from_->edges.push_back(e);
	}

	static void addUndirectedEdge(Node* from_, Node* to_, double weight_) {
		Edge::addEdge(from_, to_, weight_);
		Edge::addEdge(to_, from_, weight_);
	}
};


void print(std::vector<Node*> graph){
	for (auto& node : graph) {
		std::cout << "Node " << node->id << ":\n";
		for (Edge* e : node->edges) {
			std::cout << "  -> " << e->to->id
				<< " (waga = " << e->weight << ")\n";
		}
	}
}

inline void DFS(Node* start, size_t size) {
    if (!start) return;
    if ((size_t)start->id >= size) return;

    std::vector<bool> visited(size, false);
    std::stack<Node*> s;

    s.push(start);

    while (!s.empty()) {
        Node* cur = s.top();
        s.pop();
        if (!cur) continue;

        // ochrona gdyby id wysz³o poza zakres
        if ((size_t)cur->id >= size) continue;

        if (visited[cur->id]) continue;
        visited[cur->id] = true;

        std::cout << cur->id << " ";

        // ¿eby DFS by³ bardziej "klasyczny" (pierwsza krawêdŸ odwiedzana pierwsza),
        // wrzucamy s¹siadów w odwrotnej kolejnoœci
        for (int i = (int)cur->edges.size() - 1; i >= 0; --i) {
            Edge* e = cur->edges[i];
            if (!e || !e->to) continue;

            Node* nxt = e->to;
            if ((size_t)nxt->id < size && !visited[nxt->id]) {
                s.push(nxt);
            }
        }
    }

    std::cout << "\n";
}

// --- BFS (kolejka) ---
inline void BFS(Node* start, size_t size) {
    if (!start) return;
    if ((size_t)start->id >= size) return;

    std::vector<bool> visited(size, false);
    std::queue<Node*> q;

    visited[start->id] = true;
    q.push(start);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        if (!cur) continue;

        std::cout << cur->id << " ";

        for (Edge* e : cur->edges) {
            if (!e || !e->to) continue;

            Node* nxt = e->to;
            if ((size_t)nxt->id >= size) continue;

            if (!visited[nxt->id]) {
                visited[nxt->id] = true;
                q.push(nxt);
            }
        }
    }

    std::cout << "\n";
}



#endif 

















