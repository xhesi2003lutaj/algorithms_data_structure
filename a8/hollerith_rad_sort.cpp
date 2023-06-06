#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void printa(vector<int>&arr){
		for(int i=0;i<arr.size();i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}
int reurnmax(vector<int>&arr){
		int max=arr[0];
		for(int i=0;i<arr.size();i++){
				if(arr[i]>max){
						max=arr[i];
				}
		}
		return max;
}
void bucketsort(vector<int>&arr,int po){
		cout<<"po "<<po<<endl;
		if(po==0){
				return;
		}
		vector<int>b[10];
		for(int i=0;i<arr.size();i++){
				int n=((arr[i]/po)%10);
				b[n].push_back(arr[i]);
		}
		for(int i=0;i<10;i++){
				if(b[i].size()>1){
						bucketsort(b[i],po/10);

				}
		}

		arr.clear();
		for(int i=0;i<10;i++){
				for(int j=0;j<b[i].size();j++){

     					arr.push_back(b[i][j]);
				}
		}
}
void radixsort(vector<int>&arr){
		int exp=reurnmax(arr);
		int count=0;
		while((exp%10)!=0){
				count++;
				exp/=10;
		}
		cout<<"count "<<count<<endl;

		bucketsort(arr,pow(10,count));
}

int main(){
		vector<int>arr;
		arr.push_back(2);
		arr.push_back(2);
		arr.push_back(2);
		arr.push_back(2);
		arr.push_back(2);
		radixsort(arr);
		printa(arr);

}




/* #include<iostream>
#include<cmath>
using namespace std;

void printarr(int arr[],int n){
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}
int returnmax(int arr[],int n){
int max=arr[0];
for(int i=0;i<n;i++){
if(arr[i]>max){
max=arr[i];
}
}
return max;
}
void countingsort(int arr[],int n,int pos){
int siz=returnmax(arr,n);
int *b=new int[siz];
int *out=new int[n];
memset(b,0,sizeof(*b));
printarr(b,siz);
for(int i=0;i<n;i++){
b[(arr[i]/pos)%10]++;
}
printarr(b,siz);
for(int i=1;i<siz;i++){///mot <=
b[i]+=b[i-1];
}
for(int i=n-1;i>=0;i--){
out[b[(arr[i]/pos)%10]-1]=arr[i];
b[(arr[i]/pos)%10]--;
}
for(int i=0;i<n;i++){
arr[i]=out[i];
}
delete[]out;
delete []b;

}
void radixsort(int arr[],int n){
int d=returnmax(arr,n);
int count=0;
while((d%10)!=0){
count++;
d/=10;
}
for(int i=count;i>=1;i--){
countingsort(arr,n,pow(i,10));
} 

}

int main(){
int arr[]={1, 10, 2, 3, 4, 5, 6, 7, 8, 9};
int n=sizeof(arr)/sizeof(int);
radixsort(arr,n);
printarr(arr,n);

} */
