// Lab0605.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedGraph.h"
#include "Queues.h"

int main()
{
	linkedGraph<double, double> graph;
	graph.addNode(33);
	graph.addNode(22);
	graph.addNode(28);
	graph.addNode(29);
	graph.addNode(11);
	graph.addNode(98);
	graph.addNode(82);

	graph.addEdge(33, 22);
	graph.addEdge(33, 28);
	graph.addEdge(33, 29);
	graph.addEdge(22, 28);
	graph.addEdge(28, 11);
	graph.addEdge(11, 29);
	graph.addEdge(11, 33);
	graph.addEdge(11, 11);
	graph.addEdge(11, 82);
	graph.addEdge(33, 82);
	graph.addEdge(98, 82);
	graph.addEdge(29, 82);
	graph.showAll();
	cout << endl;

	graph.hardLinked();

	linkedGraph<double, double> graphLinked;
	graphLinked.addNode(1);
	graphLinked.addNode(2);
	graphLinked.addNode(3);
	graphLinked.addNode(4);
	graphLinked.addEdge(1, 2);
	graphLinked.addEdge(2, 1);
	graphLinked.addEdge(2, 3);
	graphLinked.addEdge(3, 4);
	graphLinked.addEdge(4, 3);
	graphLinked.addEdge(3, 2);

	graphLinked.showAll();
	cout << endl;

	graphLinked.hardLinked();

	system("pause");
	return 0;
}

