#include<iostream>
#include<vector>
using namespace std;
void bucketsort(float arr[],int n){
		vector<float>b[n];
		for(int i=0;i<n;i++){
				int s=n*arr[i];
				b[s].push_back(arr[i]);

		}for(int i=0;i<n;i++){
            for(int j=0;j<b[i].size();j++){
				cout<<b[i][j]<<" ";
        }
        printf("\n");
	

		}
        printf("\n");
		for(int i=0;i<n;i++){
				sort(b[i].begin(),b[i].end());
		}
		
		for(int i=0;i<n;i++){
				for(int j=0;j<b[i].size();j++){
						arr[i]=b[i][j];

				}
		}
}

int main(){
		float arr[]={0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
		int n=sizeof(arr)/sizeof(int);
		bucketsort(arr,n);
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		printf("\n");
}
