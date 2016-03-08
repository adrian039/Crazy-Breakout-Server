/*
 * LinkedList1.cpp
 *
 *  Created on: 28 de feb. de 2016
 *      Author: adrian
 */

#include "LinkedList1.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "Player.h"

using namespace std;

//inserta el dato d antes que loc
template<typename T>
void LinkedList1<T>::insert(Node *loc, T d) {
	Node *new_node = new Node(d, 0); //Se crea un nodo con el nuevo dato con un siguiente con valor de 0 para no apuntar
	if (!head) {
		head = new_node;
		return;
	}
	if (loc == head) {
		push_front(d);
		return;
	}
	Node *cur = head;
	while (cur->next) {
		if (cur->next == loc) {
			new_node->next = cur->next;
			cur->next = new_node;
			return;
		}
		cur = cur->next;
	}
}

//Metodo que inserta al final
template<typename T>
void LinkedList1<T>::push_back(T d) {
	Node *new_node = new Node(d, 0);
	if (!head) {
		head = new_node;
		return;
	}
	Node *cur = head;
	while (cur) {
		if (!cur->next) {
			cur->next = new_node;
			return;
		}
		cur = cur->next;
	}
}
//Metodo que inserta al incio

template<typename T>
void LinkedList1<T>::push_front(T d) {
	Node *new_node = new Node(d, 0);
	if (!head) {
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;
	return;
}

//Metodo que quita el ultimo elemento de la lista
template<typename T>
T LinkedList1<T>::pop_back() {
	Node *cur = head;
	while (cur) {
		if (!cur->next) {
			T data(cur->data);
			delete cur;
			head = NULL;
			return data;
		} else {
			if (!cur->next->next) {
				T data(cur->next->data);
				cur->next = NULL;
				delete cur->next;
				return data;
			}
		}
		cur = cur->next;
	}
	return NULL;
}

//Metodo que quita el primer elemento de la lista
template<typename T>
T LinkedList1<T>::pop_front() {
	if (!head)
		return NULL;
	Node *tmp = head;
	T data(head->data);
	if (head->next) {
		head = head->next;
		delete tmp;
		return data;
	}
	delete tmp;
	head = NULL;
	return data;
}

//Metodo para borrar elementos
template<typename T>
void LinkedList1<T>::erase(Node *loc) {
	if (loc == head) {
		Node *tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	Node *cur = head;
	while (cur) {
		if (cur->next == loc) {
			cur->next = loc->next;
			delete loc;
		}
		cur = cur->next;
	}
}

//Metodo para buscar elementos

template<typename T>
typename LinkedList1<T>::Node* LinkedList1<T>::search(T d) {
	if (!head)
		return NULL;
	Node* cur = head;
	while (cur) {
		if (cur->data == d) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//Metodo que muestra la lista
template<typename T>
void LinkedList1<T>::display() {
	if (!head) {
		cout << "empty " << endl;
		return;
	}
	Node *cur = head;
	while (cur) {
		cout << cur->data << " " << endl;
		cur = cur->next;
	}
	cout << endl;
}
template<typename T>
void LinkedList1<T>::displayPlayers() {
	if (!head) {
		cout << "empty " << endl;
		return;
	}
	Node *cur = head;
	while (cur) {
		Player player = (Player) (cur->data);
		string username = player.getUsername();
		cout << username << " " << endl;
		cur = cur->next;
	}
	cout << endl;
}

template<typename T>
int LinkedList1<T>::getLenght() {
	int c = 0;
	if (!head)
		return 0;
	Node *cur = head;
	while (cur) {
		c = c + 1;
		cur = cur->next;
	}
	return c;
}

template<typename T>
void LinkedList1<T>::deleteNode(int pPos) {
	if (pPos == 0) {
		Node *tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	int c = 0;
	Node *cur = head;
	while (cur) {
		if ((c + 1) == pPos) {
			Node *temp = cur->next;
			cur->next = temp->next;
			delete temp;
			break;
		}
		c = c + 1;
		cur = cur->next;
	}

}

template<typename T>
T LinkedList1<T>::getData(int pos) {
	int c = 0;

	Node* cur = head;
	while (cur) {
		if (c == pos) {
			return cur->data;
		}
		c = c + 1;
		cur = cur->next;
	}

}

