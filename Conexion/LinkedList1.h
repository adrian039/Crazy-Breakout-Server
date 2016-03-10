/*
 * LinkedList1.h
 *
 *  Created on: 28 de feb. de 2016
 *      Author: adrian
 */

#ifndef LINKEDLIST1_H_
#define LINKEDLIST1_H_
#include <iostream>
template<typename T>
class LinkedList1 {
	struct Node {
		T data;
		Node *next;
		Node(T d, Node *n = 0) :
				data(d), next(n) {
		}
	};
	Node *head;
public:

	LinkedList1(Node *h = 0) :
			head(h) {

	}
	void insert(Node *loc, T d);
	void push_back(T d);
	void push_front(T d);
	T pop_back();
	T pop_front();
	void erase(Node *loc);
	void display();
	void displayPlayers();
	Node *search(T d);
	int getLenght();
	void deleteNode(int);
	T getData(int pos);

};

#endif /* LINKEDLIST1_H_ */
