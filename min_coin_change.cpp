#include<iostream>
using namespace std;
void min_coin(int arr[],int sum,int n){
    int dp[n+1][sum+1];
    for(int i=1;i<=sum;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=min(dp[i-1][j],1+(dp[i][j-arr[i-1]]));
            }
        }
    }
    cout<< dp[n][sum]<<endl;
}
int main(){
    int arr[]={9, 6, 5, 1};
    int n=sizeof(arr)/sizeof(int);
    int sum=11;
    min_coin(arr,sum,n);
    return 0;
}