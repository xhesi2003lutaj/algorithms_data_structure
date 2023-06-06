#include<iostream>
using namespace std;

int fib_naive_rec(int n){
		if(n<2){
				return n;
		}
		else{
				return (fib_naive_rec(n-1)+ fib_naive_rec(n-2));
		}
}

int main(){
		int num;
		cin>>num;
		cout<<"Fibonacci of "<<num<<" is: "<<fib_naive_rec(num)<<endl;

		return 0;
}
