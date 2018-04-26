#include<iostream>
#include"linkedList.cpp"
#include"graph.cpp"
using namespace std;

int main()
{

	int cntr = 0; int index = 5; bool testLinkedListOnly = false;
	if(testLinkedListOnly) 	//linkedlist only
	{
		while(1)
		{
			int* a = new int[10];
			double* b = new double[10];
			LinkedList<int>* first = new LinkedList<int>();
			LinkedList<double>* second = new LinkedList<double>();
			for(int i=0; i<10; i++)
			{
				a[i]=100*cntr+i; b[i]=100*cntr+i*i;
				first->AddNode(a[i]); second->AddNode(b[i]);
			}
			cout << first->At(index)->data << endl;
			delete(first); delete(second);
			delete(a); delete(b);
			cntr++;
		}
	}
	else  // graph
	{
		while(1)
		{
			long* a = new long[10];
			Graph<long>* myGraph = new Graph<long>();
			for(int i=0; i<10; i++)
			{
				a[i]=10*cntr+i;
				myGraph->AddNode(a[i]);
				for(int j=0; j<i; j++)
				{
					if(i!=j)
						myGraph->JoinNodes(i,j);
				}
			}
			cout << myGraph->At(index)->data << endl;
			delete [] a; delete myGraph;
			cntr++;
		}
	}	
	return 0;
}
