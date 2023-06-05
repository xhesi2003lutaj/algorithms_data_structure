#include<iostream>
using namespace std;

//Complex class.
class Complex
{
private:
    int real;
    int imag;
public:
    Complex(int r,int m){
        real=r;
        imag=m;
    }
    ~Complex(){
    }
    Complex(const Complex &obj){
    real = obj.real;
    imag = obj.imag;
}
    void print();

    bool operator==(const Complex&);
/*   friend bool operator==(Complex &lhs, Complex &rhs){
    if((lhs.real==rhs.real)&& (lhs.imag==rhs.imag)){
        return 1;
    }else{
        return -1;
    }
  } */

};
//overloaded comparison operator
bool Complex::operator==(const Complex &obj)
{
    if (real == obj.real && imag == obj.imag)
    {
        return 1;
    }
    return 0;
}
//The array search, generic
//determines if that element is in the array or not
template<class T>
int findelement(T arr[],T look,int size){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==look){
            return i;
        }
              //break; if you want to find all occurrencies
        }
              return -1;
}
//a test program
int main(){
    string arr[]={"beni","tomi","ana","miri"};
    cout<<"Found at index: \n";
    string look="ana";
    cout<<"String: ";
    cout<<findelement(arr,look,4)<<endl;
    
    int arri[]={1,2,3,4,5,6,7,8,9};
    cout<<"Int: ";
    cout<<findelement(arri,5,8)<<endl;
    
    //Complex objects
    Complex hel[4]={Complex(1,1),Complex(4,2),Complex(2,2),Complex(3,2)};
    Complex find(2,2);
    cout<<"Complex ";
    cout<<findelement<Complex>(hel,find,4)<<endl;
    return 0;
}