#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketsort(double arr[],int n){
    vector<double>b[n];
    vector<double>output;
    for(int i=0;i<n;i++){
        //cout<<"first for loop\n";
        int num=n*arr[i];
        b[num].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        sort(b[i].begin(),b[i].end());
    }
    int index=0;
    for(int i=0;i<n;i++){
      //  cout<<"second for loop\n";
        for(int j=0;j<b[i].size();j++){
            arr[index++]=b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}
int main(){
    double arr[]={0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketsort(arr,n);

}