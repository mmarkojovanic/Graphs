#include "linkedList.h"
#include<iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
	this->head = nullptr;
}
template <class T>
LinkedList<T>::LinkedList(T& data){
	this->head = new LinkedListNode<T>{data, nullptr};
}
template <class T>
LinkedList<T>::~LinkedList(){
	LinkedListNode<T>* temp1 = this->head, * temp2;
	while(temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		delete temp2;
	}
}
template <class T>
LinkedListNode<T>* LinkedList<T>::At(int& i)
{ 
	LinkedListNode<T>* temp = this->head; int cntr = 0;
	while (cntr < i)
	{
		temp=temp->next;
		if(!temp) return nullptr;
		cntr++;
	}
	return temp;
}
template <class T>
void LinkedList<T>::AddNode(T& data)
{
	if(!this->head)	{this->head = new LinkedListNode<T>{data, nullptr}; return;}
	LinkedListNode<T>* temp = this->head;
	while(temp->next)
	{
		temp=temp->next;
	}
	LinkedListNode<T>* newNode = new LinkedListNode<T>{data, nullptr};
	temp->next = newNode;
}
template <class T>
void LinkedList<T>::Traverse()
{
	LinkedListNode<T>* temp = this->head;
	while(temp){
		cout << temp->data << endl;
		temp = temp->next;
	}
}
template <class T>
LinkedListNode<T>* LinkedList<T>::PopFirst() // must be deallocated explicitly after call
{
	if(!head) return nullptr;
	LinkedListNode<T>* ret = head;
	head = head->next; ret->next = nullptr;
	return ret;
}
template <class T>
bool LinkedList<T>::RemoveNode(T* node) //not tested
{
	if(!head) return false;
	LinkedListNode<T>* temp = this->head, *prev;
	if(head==node){temp = this->head->PopFirst(); delete temp; return true;}
	prev = temp; temp = temp->next;
	while(temp)
	{
		if(temp == node)
		{
			prev->next = temp->next;
			temp->next = nullptr; delete temp;
			return true;
		}
		prev = temp;
		temp=temp->next;
	}
	return false;
}

