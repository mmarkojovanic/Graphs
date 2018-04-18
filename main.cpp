#include<iostream>
#include"linkedList.cpp"
using namespace std;

int main()
{
	//linkedlist only
	int cntr = 0; int index = 5;
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
	// graph
	

	return 0;
}
