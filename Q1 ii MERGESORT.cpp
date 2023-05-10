#include<iostream>
#include<stdlib.h>
using namespace std;

void merge(int *arr, int s, int e,int &count){
	
    int mid=(s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int mainindex = 
	s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainindex++];
    }
    
     mainindex=mid+1;
     
    for(int i=0;i<len2;i++){
        second[i]=arr[mainindex++];
    }

    int index1=0;
    int index2=0;
    
    mainindex=s;
    
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            count=count+1;
            arr[mainindex++]=first[index1++];
        }
        else{
            count=count+1;
            arr[mainindex++]=second[index2++];
        }
    }
    
        while(index1<len1){
            arr[mainindex++]=first[index1++];

        }
        while(index2<len2){
            arr[mainindex++]=second[index2++];

        }
    return;
        
    }
    
void mergesort(int *arr, int s, int e,int &count){ 
if(s>=e){
    return;
}
int mid=(s+e)/2;

mergesort(arr,s,mid,count);

mergesort(arr,mid+1,e,count);

merge(arr,s,e,count);

}

void display(int arr[], int n)
{
	for(int i = 0; i<n; i++)
   cout << arr[i] << " ";
   cout << endl;	
}


int main(){
   
    int count=0;
    int n;  
        
	cout<<"\nEnter the number of terms: ";
	cin>>n;
	
	int arr[n];
	
	cout<<"\nEnter the array to be sorted: ";
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
        mergesort(arr,0,n-1,count);
        cout<<"The sorted array is: "<<endl;
        display(arr,n);
        cout<<"The number of comparions are: "<<count;
    
}
