#ifndef LLIST_H
#define LLIST_H
#include<iostream>
using namespace std;

template <typename T>
struct LinkedListNode{
	T data;
	LinkedListNode<T>* next;
};

template <class T>
class LinkedList
{
	private:
		LinkedListNode<T>* head;
	public:
		LinkedList<T>();
		LinkedList<T>(T& data);
		~LinkedList();
		LinkedListNode<T>* At(int& i); //
		void AddNode(T& data);
		void Traverse();
		LinkedListNode<T>* PopFirst();
		bool RemoveNode(T* node);
};
#endif
