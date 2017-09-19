#pragma once
#include <iostream>
using namespace std;

template <typename type>
class Stack {
protected:
	type* array;
	long size;
	long top;
public:
	Stack(long newSize) {
		size = newSize;
		array = new type[size];
		top = -1;
	}
	~Stack() {
		delete[] array;
	}

	bool isEmpty() {
		return top == -1;
	}

	long numberOfElements() {
		return top + 1;
	}

	void push(type element) {
		if (top == size - 1)
			throw new std::exception("Stack is full.");
		array[++top] = element;
	}

	type pop() {
		if (top == -1)
			throw new std::exception("Stack is empty.");
		type tmp = array[top--];
		return tmp;
	}

	type getTop() {
		if (top == -1)
			throw new std::exception("Stack is empty.");
		return array[top];
	}
};

template <typename type>
class Queue {
protected:
	type* array;
	long size;
	long head;
	long tail;
	long numOfElements;
public:
	Queue(long newSize) {
		size = newSize;
		array = new type[size];
		head = tail = -1;
		numOfElements = 0;
	}
	~Queue() {
		delete[] array;
	}

	bool isEmpty() {
		return numOfElements == 0;
	}

	long numberOfElements() {
		return numOfElements;
	}

	type getHead() {
		if (numOfElements == 0)
			throw new std::exception("Queue is empty.");
		return array[head];
	}

	void enqueue(type element) {
		if (numOfElements == size)
			throw new std::exception("Queue is full.");
		if (++tail == size)	// increase tail by mod N
			tail = 0;
		array[tail] = element;
		if (numOfElements == 0)	// add to empty queue edge case
			head = tail;
		numOfElements++;
	}

	type dequeue() {
		if (numOfElements == 0)
			throw new std::exception("Queue is empty.");
		type tmp = array[head];
		if (++head == size)	// increase head by mod N
			head = 0;
		numOfElements--;
		if (numOfElements == 0)	// remove from one-element queue edge case
			head = tail = -1;
		return tmp;
	}
};