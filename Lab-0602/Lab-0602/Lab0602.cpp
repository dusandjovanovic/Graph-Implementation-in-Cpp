// Lab0602.cpp : Defines the entry point for the console application.
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

	graph.nodeInput();

	system("pause");
	return 0;
}

