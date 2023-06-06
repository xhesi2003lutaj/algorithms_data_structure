#include<iostream>
using namespace std;
int fib_bottom_up(int n){
		if(n==1 || n==0){
				return n;
		}

		int pre=1;
		int pre_pre=0;
		int i=1;
		while(i<n){
				int temp=pre+pre_pre;
				pre_pre=pre;
				pre=temp;
				i++; 
		}
		return pre;
}

int main(){
		int n;
		cout<<"input nr: ";
		cin>>n;
		cout<<fib_bottom_up(n)<<endl;

		return 0;
}
