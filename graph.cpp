#include"graph.h"
#include<iostream>
using namespace std;
template <class T>
Graph<T>::Graph()
{
	this->nodes = new LinkedList<GraphNode<T>*>();
}
template <class T>
Graph<T>::~Graph()
{
	int i = 0;
	if (!this->nodes->At(i)) {delete nodes; return;}
	GraphNode<T>* temp = this->nodes->At(i)->data;
	while(1)
	{
//		cout << "Deleting GraphNode at: "<< i << endl;
		delete temp->to; delete temp->from; delete temp; i++;
		if(!this->nodes->At(i)) break;
		temp = this->nodes->At(i)->data;
	}
}
template <class T>
void Graph<T>::AddNode(T& data)
{
	GraphNode<T>* newNode = new GraphNode<T>{data, nullptr, nullptr};
	this->nodes->AddNode(newNode);
//	cout << "GraphNode created, data: "<< data << endl;
}
template <class T>
GraphNode<T>* Graph<T>::At(int& i)
{
	return this->nodes->At(i)->data;
}
template <class T>
void Graph<T>::JoinNodes(int&i, int&j) // symmetric
{
	GraphNode<T>* prev = this->nodes->At(i)->data;
	GraphNode<T>* next = this->nodes->At(j)->data;
	if (!prev->to) prev->to = new LinkedList<GraphNode<T>*>();
	prev->to->AddNode(next);
	if (!next->from) next->from = new LinkedList<GraphNode<T>*>();
	next->from->AddNode(prev);
//	cout << "Nodes "<< i << " and " << j << " joined" << endl;
}

//template <class T>
//void Graph<T>::Traverse()
//{
//	
//}
//template <class T>
//void Graph<T>::BreadthFirst()
//{
//	
//}
//template <class T>
//void Graph<T>::DepthFirst()
//{
//	
//}
