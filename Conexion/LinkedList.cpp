/*
 * LinkedList.cpp
 *
 *  Created on: 27 de feb. de 2016
 *      Author: adrian
 */
#include <iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

template <typename T>
class List
{
	//Se crea la estrutura Nodo con T como dato, se crean nodos para siguiente y para head
	struct Node
	{
		T data;
		Node *next;
		Node(T d, Node *n = 0):data(d), next(n) {}//Este metodo crea el nodo con el dato d y apunta a un siguiente con valor cero en java seria NUll
	};
	Node *head;

	//Se crean los metodos que sevan autilizar
public:
	List(Node *h = 0):head(h){}
	~List(); //No se para que es esto pero si se lo quito se despicha
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

//inserta el dato d antes que loc
template <typename T>
void List<T>::insert(Node *loc, T d)
{
	Node  *new_node = new Node(d,0);//Se crea un nodo con el nuevo dato con un siguiente con valor de 0 para no apuntar
	if(!head) {
		head = new_node;
		return;
	}
	if(loc == head) {
		push_front(d);
		return;
	}
	Node *cur = head;
	while(cur->next) {
		if(cur->next == loc) {
			new_node->next = cur->next;
			cur->next = new_node;
			return ;
		}
		cur = cur->next;
	}
}

//Metodo que inserta al final
template <typename T>
void List<T>::push_back(T d)
{
	Node *new_node = new Node(d,0);
	if(!head) {
		head = new_node;
		return;
	}
	Node *cur = head;
	while(cur) {
		if(!cur->next) {
			cur->next = new_node;
			return;
		}
		cur = cur->next;
	}
}
//Metodo que inserta al incio

template <typename T>
void List<T>::push_front(T d)
{
	Node *new_node = new Node(d,0);
	if(!head) {
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;
	return;
}

//Metodo que quita el ultimo elemento de la lista
template <typename T>
T List<T>::pop_back()
{
	Node *cur = head;
	while(cur) {
		if(!cur->next) {
			T data (cur->data);
			delete cur;
			head = NULL;
			return data;
		}
		else {
			if(!cur->next->next)  {
				T data (cur->next->data);
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
template <typename T>
T List<T>::pop_front()
{
	if(!head) return NULL;
	Node *tmp = head;
	T data (head->data);
	if(head->next) {
		head = head->next;
		delete tmp;
		return data;
	}
	delete tmp;
	head = NULL;
	return data;
}

//Metodo para borrar elementos
template <typename T>
void List<T>::erase(Node *loc)
{
	if(loc == head) {
		Node *tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	Node *cur = head;
	while(cur) {
		if(cur->next == loc) {
			cur->next = loc->next;
			delete loc;
		}
		cur = cur->next;
	}
}

//Metodo para buscar elementos

template <typename T>
typename List<T>::Node* List<T>::search(T d)
{
	if(!head) return NULL;
	Node* cur = head;
	while(cur) {
		if(cur->data == d) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//Metodo que muestra la lista
template <typename T>
void List<T>::display()
{
	if(!head) return;
	Node *cur  = head;
	while(cur) {
		cout << cur->data << " " << endl;
		cur = cur->next;
	}
	cout << endl;
}

template <typename T>
int List<T>::getLenght()
{
	int c=0;
	if(!head) return 0;
	Node *cur  = head;
	while(cur) {
		c=c+1;
		cur = cur->next;
	}
	return c;
}

template <typename T>
void List<T>::deleteNode(int pPos)
{
	if(pPos == 0) {
			Node *tmp = head;
			head = head->next;
			delete tmp;
			return;
		}
	int c=0;
	Node *cur  = head;
	while(cur) {
		if((c+1)==pPos){
			Node *temp=cur->next;
			cur->next=temp->next;
			delete temp;
			break;
		}
		c=c+1;
		cur = cur->next;
	}

}

template<typename T>
T List<T>::getData(int pos) {
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
//Main para prueba
/*
int main()
{
	List<int> *myList = new List<int>(NULL);

	myList->push_back(20);
	myList->push_back(30);
	myList->push_back(40);
	myList->push_back(50);
	myList->display();

	myList->push_front(10);
	myList->display();

	myList->erase(myList->search(30));
	myList->display();

	myList->insert(myList->search(40),30);
	myList->display();

	cout << "pop_back()\n";
	cout << myList->pop_back() << " just back popped\n\n";
	myList->display();

	cout << "pop_front()\n";
	cout << myList->pop_front() << " just front popped\n\n";
	myList->display();

	cout << "search() 30\n";
	cout << myList->search(30);

	return 0;
}
*/


