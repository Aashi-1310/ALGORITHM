//Implement Heap Sort(The program should report the number of comparisons)

#include <iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

void heapify (int a[], int n, int i,int& count)
{
	int largest = i;
	int l= 2*i+1 ;
	int r= 2*i+2 ;
	if(l<n && ++count && a[l]>a[largest])
	{
		largest=l;
	}
	if(r<n && ++count && a[r]>a[largest])
	{
		largest=r;
	}
	if (largest!=i)
	{
		swap(a[i],a[largest]);   
		heapify(a,n,largest,count);
	}
}

void buildheap(int a[], int n,int& count)
{
	for(int i=(n/2)-1 ;i>=0;i--)
	{
		heapify(a,n,i,count);
	}
}

void heapsort(int a[], int n,int& count)
{
	buildheap(a,n,count);
	for(int i=n-1; i>=0; i--)
	{
		swap(a[0],a[i]);
		heapify(a,i,0,count);
	}
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void display(int a[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	int count=0;
	cout<<"Enter the size of array:\n";
	cin>>n;
	int *a= new int [n];
	cout<<"Enter elements of the array: \n";
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"The array is: \n";
	display(a,n);
	heapsort(a,n,count);
	cout<<"The sorted array is: \n";
	display(a,n);
	cout<<"Number of Comparisions are: "<<count;
  return 0;
  }
  
