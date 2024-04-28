#include<iostream>
#include<cmath>
using namespace std;

		int main(){
		int n,gap;
		cout<<"Enter the size of array: ";
		cin>>n;
		
		
		int arr[n];
		cout<<"Enter the element of the array: "<<endl;
		
		for(int i = 0; i<n; i++ ){
			
			cin>>arr[i];
		}
		
		cout<<"The array before sorting is: "<<endl;
		for(int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl; 
		cout<<endl;
		for(gap = floor(n/2); gap>0; gap = floor(gap/2)){
			for (int i = gap; i < n; i++) {
				int temp = arr[i];
				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
			   		arr[j] = arr[j - gap];
               	}
         		arr[j] = temp;
			}
		}
			cout<<"The arrays after sorting is: "<<endl;
			for( int i = 0; i<n; i++ ){
				cout<<arr[i]<<" ";
			}
		
	}