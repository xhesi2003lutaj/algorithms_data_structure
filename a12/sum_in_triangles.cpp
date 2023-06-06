#include<iostream>
#include<vector>
using namespace std;

void solve(){
		int n;
		cout<<"enter nr of rows: ";
		cin>>n;
		int tr[n][n];
		int cp[n][n];
		int max_idx[n][n];
		for(int i=0;i<n;i++){
				*tr[i]=0;
				for(int j=0;j<=i;j++){
						cin>>tr[i][j];
				} 
		}
		for(int i=0;i<n;i++){
				*cp[i]=0;
				for(int j=0;j<=i;j++){
						cp[i][j]=tr[i][j];
				} 
		}

		cout<<endl;
		//cout<<"last\n";cout<<endl;
		//cout<<tr[n-1][n];
		for(int i=n-2;i>=0;i--){
				for(int j=0;j<=i;j++){
						if(tr[i+1][j]>tr[i+1][j+1]){
								max_idx[i][j] = j;

						}else{
								max_idx[i][j] = j+1;
						}

						tr[i][j]+=max(tr[i+1][j],tr[i+1][j+1]);

				}
		}
		cout<<endl;

		cout<<"res\n";
		cout<<tr[0][0];

		cout<<endl;
		vector<int>path;
		int idx = 0; 
		for(int i=0;i<n-1;i++){
				path.push_back(cp[i][idx]); 
				idx = max_idx[i][idx]; 
		}
		path.push_back(cp[n-1][idx]);
		printf("\n");
		for(auto i:path){
				cout<<i<<" ";
		}
		printf("\n");
}


int main(){

		solve();
		return 0;
}
