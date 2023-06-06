#include<iostream>
using namespace std;

int partition(int arr[],int b,int h){
    int piv=arr[h];
    int i=b-1;
    int j=b;
    while(j<=h){
        if(arr[j]<piv){
            i++;
          swap(arr[i],arr[j]);
        }
        
        //i++;
        j++;
    }
    swap(arr[i+1],arr[h]);
    return (i+1);

}
void quiqsort(int arr[],int b,int e){
    if(b<e){
        int p=partition(arr,b,e);
        quiqsort(arr,b,p-1);
        quiqsort(arr,p+1,e);
    }
}

int main(){
int arr[]={9,8,0,3,-3,5,2,7,9,11,10};
    
    int n=sizeof(arr)/sizeof(arr[0]);
    quiqsort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
