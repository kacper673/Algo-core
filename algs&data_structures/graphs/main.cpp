#include <iostream>
#include <vector>
#include "graph.h"


std::vector<Node*> Graph2() {
    Node* A = Node::newNode('A');
    Node* B = Node::newNode('B');
    Node* C = Node::newNode('C');
    Node* D = Node::newNode('D');
    Node* E = Node::newNode('E');
    Node* F = Node::newNode('F');

    std::vector<Node*> graph = { A, B, C, D, E, F };


    Edge::addUndirectedEdge(A, B, 1);
    Edge::addUndirectedEdge(A, C, 4);
    Edge::addUndirectedEdge(A, D, 2);
    Edge::addUndirectedEdge(B, D, 7);
    Edge::addUndirectedEdge(C, D, 3);
    Edge::addUndirectedEdge(C, E, 1);
    Edge::addUndirectedEdge(D, F, 5);
    Edge::addUndirectedEdge(E, F, 5);

    return graph;
}

std::vector<Node*> Graph3() {
    Node* A = Node::newNode('A');
    Node* B = Node::newNode('B');
    Node* C = Node::newNode('C');
    Node* D = Node::newNode('D');
    Node* E = Node::newNode('E');
    Node* F = Node::newNode('F');

    std::vector<Node*> graph = { A, B, C, D, E, F };


    Edge::addUndirectedEdge(A, B, 6);
    Edge::addUndirectedEdge(A, C, 1);
    Edge::addUndirectedEdge(A, D, 5);
    Edge::addUndirectedEdge(B, C, 5);
    Edge::addUndirectedEdge(B, E, 3);
    Edge::addUndirectedEdge(C, D, 5);
    Edge::addUndirectedEdge(C, E, 6);
    Edge::addUndirectedEdge(C, F, 4);
    Edge::addUndirectedEdge(D, F, 2);
    Edge::addUndirectedEdge(E, F, 6);

    return graph;
}

int main() {
  
    {
        std::cout << "=========================\n";
        std::cout << "ZADANIE 2 (Kruskal - MST)\n";
        std::cout << "=========================\n";

        auto graph = Graph2();

        std::cout << "\nGraf (zad.2):\n";
        print(graph);

        std::cout << "\nBFS od A:\n";
        BFS(graph[0], graph);

        std::cout << "DFS od A:\n";
        DFS(graph[0], graph);

        std::cout << "\nMST (Kruskal):\n";
        auto mst = kruskalMST(graph);
        printMST(mst);
    }

    {
        std::cout << "\n\n======================\n";
        std::cout << "ZADANIE 3 (Prim - MST)\n";
        std::cout << "======================\n";

        auto graph = Graph3();

        std::cout << "\nGraf (zad.3):\n";
        print(graph);

        std::cout << "\nBFS od A:\n";
        BFS(graph[0], graph);

        std::cout << "DFS od A:\n";
        DFS(graph[0], graph);

        std::cout << "\nMST (Prim) start od A:\n";
        auto mst = primMST(graph, 0);
        printMST(mst);
    }

    return 0;
}
