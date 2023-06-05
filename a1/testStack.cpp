#include "Stack.h"
/*
as long as you do not provide an extend()
method, you need to check for available space and 
return false if there is no more space
*/
template<class T>
bool Stack<T>::push(T el){
    if(top==size-1){
        extend();
                     // cout<<"Stack overflow\n";
        return true;//return false;
    }else{
        count++;
        ptr[++top]=el;
    return true;
    }
}

/*
pops an element from the top of the stack
should not crash if there are no elements on the stack, but rather return false
*/
template<class T>
bool Stack<T>::pop(){
    if(top == -1){
        cout<<"underflow\n";    
        return false;
    }
    else{
        countp++;
        int x=ptr[top--];
        cout<<x<<" ";
        return true;
    }
    cout<<endl;
}

template<class T>
bool Stack<T>::isEmpty(){
    return (top<0);
}
//returns the data on the top of the stack, without changing the stack
template<class T>
T Stack<T>::back(){
    if(top<0){
        cout<<"Nothing on the top\n";
        return -1;
    }else{
        T x=ptr[top];
        return x;
    }
}
//returns the number of entries of the stack at a given moment
template<class T>
int Stack<T>::getNumEntries(){
   // return count-countp; alternative
   return top+1;
}

template<class T>
void Stack<T>::extend(){

        T *newptr=new T[2*size];
        for(int i=0;i<size;i++){
            newptr[i]=ptr[i];
        }
        delete [] ptr;
        ptr=newptr;
        size=2*size;    
}


int main(){
    Stack<int>x;
    for(int i=0;i<15;i++){
    x.push(i);
    cout<<"There are "<<x.getNumEntries()<<" elements now\n";
   }

    printf("The struct with the default size 10\n");
    while (!x.isEmpty())
    {
        x.pop();
    }
    printf("\n");
    printf("\n");
   // x.pop(); will return false and not crash the 

 
   Stack<double> l(20);
   for(int i=0;i<20;i++){
    l.push((double)i);
   }
    cout<<"The element on the top: "<<l.back()<<endl;
    printf("The struct with the non-default size\n");
    while (!l.isEmpty())
    {
        l.pop();
    }
    printf("\n");
    cout<<l.back()<<endl;//no el at the top/stack here
    cout<<"There are "<<l.getNumEntries()<<" elements now\n";


    
    return 0;
}