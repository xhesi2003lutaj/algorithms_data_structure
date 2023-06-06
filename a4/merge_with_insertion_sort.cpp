#include<iostream>
using namespace std;

void sort(int arr[],int b,int mid,int e);

void insertionsort(int arr[],int b,int e){
		//cout<<"brenda insertionsort ,"<<endl;
		int i=b;
		int j,key;
		while(i<=e){
				key=arr[i];
				j=i-1;
				while(j>=0 && arr[j]>key){
						arr[j+1]=arr[j];
						j--;

				}
				arr[j+1]=key;

				i++;
		}

}
void merge_sort(int arr[],int b,int e,int k){
		//cout<<" b: "<<b<<" e: "<<e<<endl;
		if((e-b)<=k){
				insertionsort(arr,b,e);

		}
		if(e-b>k){
				//cout<<"brenda mergesort ,";
				int mid=(b+e)/2;
				//cout<<"mid "<<mid<<endl;
				cout<<"para recursive 1 "<<endl;
				merge_sort(arr,b,mid,k);
				cout<<"pas rec 1"<<endl;
				merge_sort(arr,mid+1,e,k);
				//cout<<"sorting after recursive "<<endl;
				sort(arr,b,mid,e);
		}


}
void sort(int arr[],int b,int mid,int e){
		cout<<"brenda sort ,\n";

		int le=mid-b+1;
		int ri=e-mid;/////
		int *l=new int[le];
		int *r=new int[ri];
		for(int i=0;i<le;i++){
				l[i]=arr[i+b];

		}
		for(int j=0;j<ri;j++){
				r[j]=arr[mid+j+1];
		}
		int i=0;
		int j=0;
		int k=b;
		while(i<le && j<ri){
				if(l[i]<=r[j])
				{
						arr[k]=l[i];
						i++;
				}
				else{
						arr[k]=r[j];
						j++;
				}
				k++;
		}
		while(i<le){
				arr[k]=l[i];
				i++;
				k++;
		}
		while(j<ri){
				arr[k]=r[j];
				j++;
				k++;
		}
}
int main(){
		int arr[]={14,31,21,11,10,9,8,7,6,5,4,3,2,1};
		int size=sizeof(arr)/sizeof(int);
		int k;
		cout<<"Input k :";
		cin>>k;

		merge_sort(arr,0,size-1,k);
		for(int i=0;i<size;i++){
				cout<<arr[i]<<endl;
		}
		return 0;
}
