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
    cout<<"max "<<max;
    return max;
}
void countingsort(int a[],int n){
    int size__=findmax(a,n);
    int *c=new int[size__];
    int *b=new int[n];
  
    memset(c, 0, sizeof(*c));

      printarr(c,size__);

    for(int j=0;j<n;++j){
        cout<<"second for loop\n";
        c[a[j]]++;
    }
    for(int i=1;i<=size__;i++){
        cout<<"third for loop\n";
        c[i]=c[i]+c[i-1];
    }
    for(int i=n-1;i>=0;i--){
        cout<<"forth for loop\n";
        b[c[a[i]]-1]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }

}
int main(){
    int arr[]={8,9,1,3,2,4,0,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    countingsort(arr,n);
    printarr(arr,n);
    
}