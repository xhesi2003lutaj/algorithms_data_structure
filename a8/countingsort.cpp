#include<iostream>
using namespace std;
void printarr(int arr[],int n){
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}
int findmax(int arr[],int n){
		int max=arr[0];
		for(int i=0;i<n;i++){
				if(arr[i]>max){
						max=arr[i];
				}
		}
		return max;
}

void countingsort(int arr[],int n){
		int s=findmax(arr,n);
		int *c=new int[s];
		int *out=new int[n];
		memset(c,0,sizeof(*c));

		for(int i=0;i<n;i++){
				//cout<<"inside second\n";
				c[arr[i]]++;
		}

		for(int i=1;i<=s;i++){
				//cout<<"inside third\n";
				c[i]=c[i]+c[i-1];   
		}

		for(int i=n-1;i>=0;i--){
				out[c[arr[i]]-1]=arr[i];
				c[arr[i]]=c[arr[i]]-1;
		}


		for(int i=0;i<n;i++){
				//cout<<"inside fifth\n";
				arr[i]=out[i];
		}




}
int main(){
		int arr[]={9, 1, 6, 7, 6, 2, 1};
		int n=sizeof(arr)/sizeof(arr[0]);
		countingsort(arr,n);
		printarr(arr,n);

}
