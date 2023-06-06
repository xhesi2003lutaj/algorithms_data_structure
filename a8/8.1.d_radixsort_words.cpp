#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#define MAX 255
int maxlen(string arr[],int n){
		int max=arr[0].length();
		for(int i=0;i<n;i++){
				if(arr[i].length()>max){
						max=arr[i].length();
				}
		}
		return max;
}
void countsort(string arr[],int n,int pos){


		string *out=new string[n];
		int *c=new int[MAX];
		memset(c,0,sizeof(*c));
		int idx=0;
		for(int i=0;i<n;i++){	
				if(pos<arr[i].length()){
						idx=arr[i][pos];
				}	else{
						idx=0;
				}
				c[idx]++;
		}

		for(int i=0;i<MAX;i++){
				cout<<c[i]<<" ";
		}
		cout<<endl;
		cout<<"//////////////////////////////////////////////////////////////////"<<endl;
		cout<<endl;

		for(int i=1;i<=MAX;i++){
				//cout<<"inside third\n";
				c[i]=c[i]+c[i-1];   
		}


		for(int i=n-1;i>=0;i--){
				if(pos<arr[i].length()){
						idx=arr[i][pos];///////////////////(int)
				}else{
						idx=0;
				}
				out[c[idx]-1]=arr[i];
				c[idx]--;
		}


		for(int i=0;i<n;i++){
				//cout<<"inside fifth\n";
				arr[i]=out[i];
		}


}
void radixsort(string arr[],int n){
		int d=maxlen(arr,n);
		int i=d-1;
		while(i>=0){
				countsort(arr,n,i);
				i--;
		}

}
int main(){
		string arr[]={"word", "category", "cat", "new", "news", "world", "bear","at", "work", "time"};
		int n=sizeof(arr)/sizeof(arr[0]);
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;

		/*         cout<<arr[0].at(3)<<endl;
				   cout<<endl; */


		radixsort(arr,n);

		cout<<"Soerted array\n";
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}


