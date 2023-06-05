#include<iostream>
using namespace std;


int count=0;
int countp=0;
template<class T>
class Stack{
    T *ptr;
    int size;
    int top;
    public:
    //adds element to the top of the stack
    bool push(T el);
    bool pop();
    bool isEmpty();
    T back();
    void extend();
    int getNumEntries();
    //this constructor initializes the stack to a size of 10
    Stack(){
        size=10;
        top=-1;
        ptr=new T[size];
    }
    //copy constructor,
    Stack(const Stack& b){
        this->size=b.size;
        ptr=new T[this->size];
        for(int i=0;i<this->size;i++){
            ptr[i]=b.ptr[i];
        }
    }
    Stack(int newsize){
        size=newsize;
        top=-1;
        ptr=new T[size];
    }
    ~Stack(){
        delete [] ptr;
    }
}; 
