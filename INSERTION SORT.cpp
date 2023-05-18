//Implement Insertion Sort (The program should report the number of comparisons)

#include<iostream>
using namespace std;

template <typename E> 
class insertionSort{
	public:
		void swap(E& a,E& b){
			E temp=a;
			a=b;
			b=temp;
		}
		
		void inSort(E a[],int n)
		{
				E temp;
				int j;
				int count=0;
				
				for(int i=1; i<n; i++)
				{
					temp = a[i];
					j = i-1;
					
					while(j >=0 && ++count && a[j] > temp)
					{
						a[j+1] = a[j];
						j--;
					}
					
					a[j+1] = temp;
				}
				display(a,n);
				cout<<"\nNumber of Comparisions are: "<<count;
			}
				
		void display(E a[], int n){
			cout<<"The sorted list is: ";
			for(int i=0; i<n; i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
};

int main()
{
	insertionSort <int> s;
	int n;
	
	cout<<"\nEnter the number of terms: ";
	cin>>n;
	
	int arr[n];
	
	cout<<"\nEnter the array to be sorted: ";
	for(int i=0; i<n; i++)
		cin>>arr[i];
	s.inSort(arr,n);
}
