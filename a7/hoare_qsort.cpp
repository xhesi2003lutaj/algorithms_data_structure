#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
int hoare_partition(int arr[],int b,int e){
		int mid=b;
		int piv=arr[mid];
		int i=b-1;
		int j=e+1;
		while(1){
				do{
						i++;
				}while(arr[i]<piv);

				do{
						j--;
				}while(arr[j]>piv);

				if(i>=j){
						return j;
				}
				swap(arr[i],arr[j]);

		}
		//return j;

}
void qsort(int arr[],int b,int e){
		if(b>=e){
				return;
		}
		{
				int p=hoare_partition(arr,b,e);
				qsort(arr,b,p);


				qsort(arr,p+1,e);
		}
}
int main(){
        int arr[1000];
        for(int i=0;i<1000;i++){
            arr[i]=0 + (rand() % 1000);
        }

		cout<<endl;
		//int arr[]={5,3,2,6,67,8,8,9,29,3,6,3,4224,5};
		int n=sizeof(arr)/sizeof(int);
		qsort(arr,0,n-1);
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}
