#include<iostream>
using namespace std;

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int lomuto_partition(int arr[],int b,int e){
    int piv=arr[e];
    int i=b-1;int j=b;
    for(int n=b;n<e;n++){
        if(arr[n]<piv){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[e]);
 return (i+1);
}

void qsort(int arr[],int b,int e){
    if(b<e){
        cout<<"b "<<b<<endl;
        cout<<"e "<<e<<endl;
        int p=lomuto_partition(arr,b,e);
        qsort(arr,b,p-1);
        qsort(arr,p+1,e);
    }
}
int main(){
    //int arr[]={2,5,7,4,22,123,29,15,0,9,11};
    int arr[1000];
        for(int i=0;i<1000;i++){
            arr[i]=0 + (rand() % 1000);
        }
        
		cout<<endl;
    int n=sizeof(arr)/sizeof(int);
    qsort(arr,0,1000);
    printarr(arr,1000);

}