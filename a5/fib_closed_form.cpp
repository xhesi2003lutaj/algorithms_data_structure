#include<iostream>
#include <cmath>
using namespace std;

#define SQ5 sqrt(5)

 int fib_closed(int n){
return (pow((1+sqrt(5))/2,n))/sqrt(5);

 }
int main(){
    int n;
    cout<<"enter nr.: ";
    cin>>n;
    cout<<fib_closed(n);

    return 0;
}