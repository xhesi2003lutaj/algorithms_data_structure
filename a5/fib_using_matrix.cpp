#include<iostream>
using namespace std;


void printing(int A[2][2]){
		for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
						cout<<A[i][j]<<" ";
				}
				cout<<endl;
		}
}
void fib_using_matrix(int n){


		int B[2][2];
		for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
						B[i][j]=1;
				}
		}
		B[1][1]=0;
		//printing(B);

		int res[2][2];
		int temp[2][2];
		for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
						res[i][j]=(i==j);
				}
		}
		int f=0;
		while(f<n){
				for(int i=0;i<2;i++){
						for(int j=0;j<2;j++){
								temp[i][j]=0;
								for(int k=0;k<2;k++){
										temp[i][j] +=res[i][k] * B[k][j];
								}
						}
				}
				f++;

				for(int i=0;i<2;i++){
						for(int j=0;j<2;j++){
								res[i][j]=temp[i][j];
						}
				}
		}
		printing(res);
}

int main(){
		int n;
		cout<<"input fib nr.: \n";

		cin>>n;
        cout<<"Your fibonacci nr:\n";
		fib_using_matrix(n);
		return 0;
}
