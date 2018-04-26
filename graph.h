#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include"linkedList.h"
using namespace std;

template <class T>
struct GraphNode{
	T data;
	LinkedList<GraphNode<T>*> *to, *from;
};

template <class T>
class Graph{
	private:
		LinkedList<GraphNode<T>*> *nodes;
	public:
		Graph<T>();
		~Graph<T>();
		GraphNode<T>* At(int& i);
		void AddNode(T& data);
		void JoinNodes(int& i, int& j);
//		void Traverse();
//		void DepthFirst();
//		void BreadthFirst();
};
#endif
