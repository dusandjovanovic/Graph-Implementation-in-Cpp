#pragma once
#include <iostream>
#include "Queues.h"
using namespace std;

template <typename type, typename weight>
class Edge;

template <typename type, typename weight>
class linkedNode {
public:
	type node;
	linkedNode<type, weight>* next;

	Edge<type, weight>* adj;
	int status;

	linkedNode() {
		adj = next = nullptr;
		status = 0;
	}

	linkedNode(type newNode) {
		node = newNode;
		adj = next = nullptr;
		status = 0;
	}

	linkedNode(type newNode, Edge<type, weight>* adjNode, linkedNode<type, weight>* nextNode, int newStatus) {
		node = newNode;
		adj = adjNode;
		next = nextNode;
		status = newStatus;
	}

	inline void showNode() {
		cout << " " << node << " ";
	}
};

template <typename type, typename weight>
class Edge {
public:
	linkedNode<type, weight>* destination;
	Edge<type, weight>* link;
	weight weightOf;

	inline Edge() {
		destination = nullptr;
		link = nullptr;
	}

	inline Edge(linkedNode<type, weight>* destinationNode, Edge<type, weight>* linkEdge) {
		destination = destinationNode;
		link = linkEdge;
	}

	void showEdge() {
		cout << ">";
		destination->showNode();
	}
};

template <typename type, typename weight>
class linkedGraph {
protected:
	linkedNode<type, weight>* start;
	long nodeNumber;
public:
	linkedGraph() {
		start = nullptr;
		nodeNumber = 0;
	}

	~linkedGraph() {

	}

	void showAll() {
		linkedNode<type, weight>* tmp = start;
		while (tmp != nullptr) {
			tmp->showNode();
			Edge<type, weight>* tmpEdge = tmp->adj;
			while (tmpEdge != nullptr) {
				tmpEdge->showEdge();
				tmpEdge = tmpEdge->link;
			}
			cout << endl;
			tmp = tmp->next;
		}
	}

	linkedNode<type, weight>* findNode(type element) {
		linkedNode<type, weight>* tmp = start;
		while (tmp != nullptr && tmp->node != element)
			tmp = tmp->next;
		return tmp;
	}

	Edge<type, weight>* findEdge(type source, type destination) {
		linkedNode<type, weight>* src = findNode(source);
		linkedNode<type, weight>* dst = findNode(destination);
		if (src == nullptr || dst == nullptr)
			return nullptr;

		Edge<type, weight>* tmpEdge = src->adj;
		while (tmpEdge != nullptr && tmpEdge->destination != dst)
			tmpEdge = tmpEdge->link;
		return tmpEdge;
	}

	bool addNode(type element) {
		linkedNode<type, weight>* node = new linkedNode<type, weight>(element, nullptr, start, 0);
		if (node == nullptr)
			return false;
		start = node;
		nodeNumber++;
		return true;
	}

	bool addEdge(type source, type destination) {
		linkedNode<type, weight>* src = findNode(source);
		linkedNode<type, weight>* dst = findNode(destination);
		if (src == nullptr || dst == nullptr)
			return false;
		Edge<type, weight>* edge = new Edge<type, weight>(dst, src->adj);
		if (edge == nullptr)
			return false;
		src->adj = edge;
		return true;
	}

	bool deleteEdge(type source, type destination) {
		Edge<type, weight>* edge = findEdge(source, destination);
		if (edge == nullptr)
			return false;

		linkedNode<type, weight>* src = findNode(source);
		if (edge == src->adj) {
			src->adj = edge->link;
			delete edge;
			return true;
		}

		Edge<type, weight>* previous = src->adj;
		while (previous->link != edge)
			previous = previous->link;
		previous->link = edge->link;
		delete edge;
		return true;
	}

	bool deleteNode(type element) {
		linkedNode<type, weight>* node;
		if (start == nullptr)
			return false;

		if (start->node == element) {
			node = start;
			Edge<type, weight>* edge = node->adj;
			while (edge != nullptr) {
				Edge<type, weight>* tmp = edge->link;
				delete edge;
				edge = tmp;
			}
			start->adj = nullptr;
			deleteEdgeToNode(start);
			node = start;
			start = start->next;
			delete node;
			nodeNumber--;
			return true;
		}
		else {
			node = start->next;
			linkedNode<type, weight>* previous = start;
			while (node->node != element) {
				previous = node;
				node = node->next;
			}
			if (node == nullptr)
				return false;

			previous->next = node->next;
			Edge<type, weight>* edge = node->adj;
			while (edge != nullptr) {
				Edge<type, weight>* tmp = edge->link;
				delete edge;
				edge = tmp;
			}

			node->adj = nullptr;
			deleteEdgeToNode(node);
			delete node;
			nodeNumber--;
			return false;
		}
	}

	void deleteEdgeToNode(linkedNode<type, weight>* node) {
		linkedNode<type, weight>* tmp = start;
		while (tmp != nullptr) {
			Edge<type, weight>* tmpEdge = tmp->adj;
			Edge<type, weight>* previous = nullptr;
			while (tmpEdge != nullptr) {
				if (tmpEdge->destination == node) {
					if (tmp->adj == tmpEdge) {
						tmp->adj = tmpEdge->link;
						delete tmpEdge;
						tmpEdge = tmp->adj;
					}
					else {
						previous->link = tmpEdge->link;
						delete tmpEdge;
						tmpEdge = previous->link;
					}
				}
				else {
					previous = tmpEdge;
					tmpEdge = tmpEdge->link;
				}
			}
			tmp = tmp->next;
		}
	}

	long bredthTraversal(type element) {
		long retValue = 0;
		linkedNode<type, weight>* node = start;
		Queue<linkedNode<type, weight>*> queue(nodeNumber);
		while (node != nullptr) {
			node->status = 1;
			node = node->next;
		}

		node = findNode(element);
		if (node == nullptr)
			return 0;

		queue.enqueue(node);
		node->status = 2;
		while (!queue.isEmpty()) {
			node = queue.dequeue();
			node->status = 3;
			node->showNode();
			retValue++;

			Edge<type, weight>* edge = node->adj;
			while (edge != nullptr) {
				if (edge->destination->status == 1) {
					queue.enqueue(edge->destination);
					edge->destination->status = 2;
				}
				edge = edge->link;
			}
		}

		cout << endl;
		return retValue;
	}

	long depthTraversal(type element) {
		long retValue = 0;
		linkedNode<type, weight>* node = start;
		Stack<linkedNode<type, weight>*> stack(nodeNumber);

		while (node != nullptr) {
			node->status = 1;
			node = node->next;
		}

		node = findNode(element);
		if (node == nullptr)
			return 0;
		stack.push(node);
		node->status = 2;

		while (!stack.isEmpty()) {
			node = stack.pop();
			node->status = 3;
			node->showNode();
			retValue++;
			Edge<type, weight>* edge = node->adj;
			while (edge != nullptr) {
				if (edge->destination->status == 1) {
					stack.push(edge->destination);
					edge->destination->status = 2;
				}
				edge = edge->link;
			}
		}

		cout << endl;
		return retValue;
	}

	long topologicalTraversal() {
		int retValue = 0;

		linkedNode<type, weight>* node;
		node = start;
		while (node != nullptr) {
			node->status = 0;
			node = node->next;
		}

		node = start;
		while (node != nullptr) {
			Edge<type, weight>* edge = node->adj;
			while (edge != nullptr) {
				edge->destination->status++;
				edge = edge->link;
			}
			node = node->next;
		}

		Queue<linkedNode<type, weight>*> queue(nodeNumber);
		node = start;
		while (node != nullptr) {
			if (node->status == 0)
				queue.enqueue(node);
			node = node->next;
		}

		while (!queue.isEmpty()) {
			node = queue.dequeue();
			node->showNode();
			retValue++;

			Edge<type, weight>* edge = node->adj;
			while (edge != nullptr) {
				edge->destination->status--;
				if (edge->destination->status == 0)
					queue.enqueue(edge->destination->status);
				edge = edge->link;
			}
		}
	}

	void hardLinked() {
		linkedNode<type, weight>* node = start;

		while (node != nullptr) {
			if (depthTraversal(node->node) != nodeNumber) {
				cout << endl << "Graph is not hard-linked.." << endl << endl;
				return;
			}
			node = node->next;
		}

		cout << endl << "Graph is hard-linked.." << endl << endl;
		return;
	}
};