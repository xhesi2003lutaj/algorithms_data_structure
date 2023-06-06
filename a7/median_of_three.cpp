#include<iostream>
using namespace std;
void printarr(int arr[],int n){
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}
int partition(int arr[],int b,int e){
		int mid = (b + e)/2;
		if(arr[mid] < arr[b]){
				swap(arr[mid],arr[b]);
		}

		if(arr[e] < arr[b]){
				swap(arr[e],arr[b]);
		}

		if( arr[mid] < arr[e]){
				swap(arr[mid],arr[e]);
		}

		int pivot = arr[e];
		int i = b- 1;
		for(int j=b;j<e;j++){
				if( arr[j] < pivot){
						i += 1;
						swap(arr[i],arr[j]);
				}

		}
		swap(arr[i+1],arr[e]);

		return (i + 1);
}



void qsort(int arr[],int b,int e){
		if(b<e){
				int p=partition(arr,b,e);
				qsort(arr,b,p-1);
				qsort(arr,p+1,e);
		}
}
int main(){

		int arr[1000];
		for(int i=0;i<1000;i++){
				arr[i]=0 + (rand() % 1000);
		}
		int n=sizeof(arr)/sizeof(int);
		qsort(arr,0,n);
		printarr(arr,n);

}


