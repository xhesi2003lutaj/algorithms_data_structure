	#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int n=3000;
void printarr(int arr[],int n){

		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}
void tri_partiton(int arr[],int b,int e,int &g,int &j){

		if(arr[b]>arr[e]){
				swap(arr[b],arr[e]);
		}
		int k=b+1,p=arr[b],q=arr[e];
		while(k<=g){
				if(arr[k]<p){
						swap(arr[k],arr[j]);
						j++;
				}
				else if(arr[k]>=q){
						while(arr[g]>q && k<g){
								g--;
						}
						swap(arr[k],arr[g]);
						g--;
						if(arr[k]<p){
								swap(arr[k],arr[j]);
								j++;
						}
				}
				k++;

		}
		j--;
		g++;
		swap(arr[b],arr[j]);
		swap(arr[e],arr[g]);

}

void qsort(int arr[],int b,int e){
		cout<<"b "<<b<<endl;
		cout<<"e "<<e<<endl;
		if(b<e){


				int rp=e-1;
				int lp=b+1;

				srand(time(NULL));
				int i=b + (rand() %( b-e));


				int x=b + (rand() %(b-e));
				swap(arr[rp],arr[i]);
				swap(arr[lp],arr[x]);

				tri_partiton(arr,b,e,rp,lp);
				qsort(arr,b,lp-1);
				qsort(arr,lp+1,rp-1);
				qsort(arr,rp+1,e);

		}
}
int main(){


		int arr[1000];
		for(int i=0;i<1000;i++){
				arr[i]=0 + (rand() % 1000);
		}
		cout<<endl;
		int n=sizeof(arr)/sizeof(int);
		qsort(arr,0,n-1);
		printarr(arr,n);


}
