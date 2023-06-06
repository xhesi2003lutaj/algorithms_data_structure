#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    bool swaped;
    for(int i=0;i<n;i++){
        swaped=false;
        cout<<"in first loop"<<endl;
        for(int j=0;j<n-i-1;j++){
            cout<<"i: "<<i<<" "<<"j: "<<j<<endl;
             if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swaped=true;
        }
       
        }
        if (swaped==false)
            break;
    }
    
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(int);

    bubblesort(arr,n);
    printarr(arr,n);
    return 0;
}