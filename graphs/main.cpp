#include <iostream>
#include "graph.h"

int main() {

	Node* a = Node::newNode(1);
	Node* b = Node::newNode(2);
	Node* c = Node::newNode(3);
	Node* d = Node::newNode(4);
	Node* e = Node::newNode(5);
	Node* f = Node::newNode(6);
	Node* g = Node::newNode(7);
	Node* h = Node::newNode(8);

	std::vector<Node*> graph = { a,b,c,d,e,f,g,h };

	Edge::addEdge(a, b, 1);
	Edge::addEdge(a, c, 2);
	Edge::addEdge(c, b, 4);
	Edge::addEdge(a, e, 1);
	Edge::addEdge(e, h, 5);
	Edge::addEdge(e, g, 3);
	Edge::addEdge(h, f, 6);
	Edge::addEdge(e, c, 2);


	print(graph);

	std::cout << "DFS: ";
	DFS(a, graph.size() + 1);

	std::cout << "BFS: ";
	BFS(a, graph.size() + 1);
}