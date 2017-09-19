// Lab0607.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "staticGraph.h"

int main()
{
	staticGraph<double, double> graphLinked(10);
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
	graphLinked.addEdge(1, 3);
	graphLinked.addEdge(2, 3);
	graphLinked.addEdge(3, 3);

	graphLinked.showAll();
	cout << endl;
	graphLinked.showMatrix();

	graphLinked.nodeInput();

	system("pause");
	return 0;
}

