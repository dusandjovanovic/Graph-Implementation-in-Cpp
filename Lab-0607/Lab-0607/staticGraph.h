#pragma once
#include <iostream>
using namespace std;

template <typename type, typename weight>
class Edge {
public:
	long source;
	long destination;
};

template <typename type, typename weight>
class staticGraph {
protected:
	type* array;
	long** adjMatrix;
	long nodeNumber;
	long graphLength;

public:
	staticGraph() {
		array = nullptr;
		adjMatrix = nullptr;
		nodeNumber = 0;
		graphLength = 0;
	}

	staticGraph(long length) {
		graphLength = length;
		nodeNumber = 0;
		array = new type[graphLength];
		adjMatrix = new long*[graphLength];

		for (long i = 0; i < graphLength; i++)
			adjMatrix[i] = new long[graphLength];

		for (long i = 0; i < graphLength; i++)
			for (long j = 0; j < graphLength; j++)
				adjMatrix[i][j] = 0;
	}

	~staticGraph() {

	}

	void showAll() {
		for (int i = 0; i < nodeNumber; i++) {
			if (array[i] != 0)
				cout << array[i];
			for (int j = 0; j < nodeNumber; j++)
				if (areNodesConnected(array[i], array[j]))
					cout << " > " << array[j];
			cout << endl;
		}
	}

	long findEdge(type source, type destination) {
		long src = findNodeIndex(source);
		long dst = findNodeIndex(destination);

		if (src == -1 || dst == -1)
			return -1;

		return adjMatrix[i][j] = 1;
	}

	bool addNode(type element) {
		if (nodeNumber >= graphLength)
			return false;

		array[nodeNumber] = element;
		nodeNumber++;
		return true;
	}

	bool deleteNode(type element) {
		long index = findNodeIndex(element);

		if (index == -1)
			return false;

		array[index] = 0;

		for (int i = 0; i < graphLength; i++) {
			adjMatrix[index][i] = 0;
			adjMatrix[i][index] = 0;
		}
	}

	bool addEdge(type source, type destination) {
		long src = findNodeIndex(source);
		long dst = findNodeIndex(destination);

		if (src == -1 || dst == -1)
			return false;

		adjMatrix[src][dst] = 1;
		return true;
	}

	bool deleteEdge(type source, type destination) {
		long src = findNodeIndex(source);
		long dst = findNodeIndex(destination);

		if (src == -1 || dst == -1)
			return false;

		adjMatrix[src][dst] = 0;
		return true;
	}

	long findNodeIndex(type element) {
		for (long i = 0; i < graphLength; i++)
			if (array[i] == element)
				return i;

		return -1;
	}

	type findNodeByIndex(long index) {
		return array[index];
	}

	bool areNodesConnected(type source, type destination) {
		long src = findNodeIndex(source);
		long dst = findNodeIndex(destination);

		if (src == -1 || dst == -1)
			return false;

		if (adjMatrix[src][dst] == 1)
			return true;
		else
			return false;
	}

	void showMatrix() {
		if (nodeNumber == 0)
			return;
		cout << endl;

		for (int i = 0; i < nodeNumber; i++) {
			for (int j = 0; j < nodeNumber; j++)
				cout << adjMatrix[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	void nodeInput() {
		if (nodeNumber == 0)
			return;

		type maxNode = array[0];
		long maxInput = 0;

		for (int i = 0; i < nodeNumber; i++) {
			long foundValue = 0;
			for (int j = 0; j < nodeNumber; j++)
				foundValue += adjMatrix[j][i];
			if (foundValue > maxInput) {
				maxInput = foundValue;
				maxNode = array[i];
			}
		}

		cout << "Node of value " << maxNode << " with input level of " << maxInput << endl;
	}
};