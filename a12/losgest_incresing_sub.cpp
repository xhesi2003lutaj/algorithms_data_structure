#include<iostream>
#include<vector>
using namespace std;
void longest_ordered(int arr[],int n){
		vector<vector<int>>x(n);
		for(int i=1;i<n;i++){
				for(int j=0;j<i;j++){
						if(arr[j]<arr[i] && x[j].size()>x[i].size()){
								x[i]=x[j];

						}
				}
				x[i].push_back(arr[i]);
		}
		vector<int> max=x[0];
		for(vector<int>i:x){
				if(i.size()>max.size()){
						max=i;
				}
		}
		for(int i:max){
				cout<<i<<endl;
		}
}

int main(){
		int arr[]={8,3,6,50,10,8 ,100, 30, 60, 40, 80};
		int n=sizeof(arr)/sizeof(arr[0]);
		longest_ordered(arr,n);
		return 0;
}




/* 
#include<iostream>                                                  // LONGEST INCRAESING SUBSEQUENCE
#include<vector>
#include<algorithm>
using namespace std;
void longest_ordered(int arr[],int n){

		vector<int>res;
		//int max=max(arr[0],arr[1]);
		int i,k;
		if(arr[0]>arr[1]){
				i=2;
				k=1;
		}
		else{
				k=0;
				i=1;
		}
		res.push_back(arr[k]);
		for(;i<n;i++){
				if(arr[i]>res.back()){
						res.push_back(arr[i]);
						for(int c=0;c<res.size();c++){
								cout<<res[c]<<endl;
						}
				}
				int count=0;
				if(arr[i]<res.back()){
						int k;
						// bool isGreater = false;
						for (int z = 0; z <i; ++z) {
								if (arr[i] <res[z]) {
										k=z;
										break;
								}
						}

						for(int j=i;j<n;j++){
								if(arr[j]>arr[i]){
										//k=j;
										count++;
								}


						} if(count>(res.size()-k)){
								res.erase((res.begin()+k),res.end());
								res.push_back(arr[i]);
								//break;
						}else if( count<=res.size()){
								//res.push_back(arr[i]);
								continue;
								//k++;
						}

				}

		}
		cout<<"\nresult\n";
		for(int c=0;c<res.size();c++){
				cout<<res[c]<<endl;
		}

}
int main(){
		int arr[]={8,3,6,50,10,8 ,100, 30, 60, 40, 80};
		int n=sizeof(arr)/sizeof(int);
		longest_ordered(arr,n);
		return 0;
}

 */