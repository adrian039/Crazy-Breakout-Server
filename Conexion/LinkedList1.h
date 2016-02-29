/*
 * LinkedList1.h
 *
 *  Created on: 28 de feb. de 2016
 *      Author: adrian
 */

#ifndef LINKEDLIST1_H_
#define LINKEDLIST1_H_

template<typename T>
class LinkedList1 {
	struct Node {
		T data;
		Node *next;
		Node(T d, Node *n = 0) :
				data(d), next(n) {
		} //Este metodo crea el nodo con el dato d y apunta a un siguiente con valor cero en java seria NUll
	};
	Node *head;
public:
	LinkedList1();
	LinkedList1(Node *h = 0) :
			head(h) {
	}
	//~LinkedList1(); //No se para que es esto pero si se lo quito se despicha
	void insert(Node *loc, T d);
	void push_back(T d);
	void push_front(T d);
	T pop_back();
	T pop_front();
	void erase(Node *loc);
	void display();
	Node *search(T d);
	int getLenght();
	void deleteNode(int);
	T getData(int pos);

};

#endif /* LINKEDLIST1_H_ */
