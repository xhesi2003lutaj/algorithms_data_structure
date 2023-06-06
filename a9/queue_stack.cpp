#include<iostream>
#include<cstdlib>
using namespace std;
int count=0;
template <class T>
class Stack{
		private:
				int size;
				int currentsize;
				struct StackNode { // linked list
						T data;
						StackNode *next;
				};
				StackNode *top;
		public:

				//StackNode *top;
				void setsize(int newsiz); 
				int getsize();
				//int size; // -1 if not set, value otherwise
				//int current_size; // unused if size = -1
				void push(T t);
				bool isEmpty();
				T pop();

				Stack(int newsize){
						this->size=newsize;
						this->currentsize=0;
						this->top=NULL;
				}
				Stack(){
						this->size=-1;
						this->currentsize=0;
						this->top=NULL;

				}
                bool isFull(){
                    if(this->currentsize>=size){
                        return true;
                    }else{
                        return false;
                    }
                }
				//Stack(int new_size)
};
template <class T>
void Stack<T>::setsize(int newsiz){
		size=newsiz;
}
template <class T>
int Stack<T>::getsize(){
		return size;
}
template <class T>
void Stack<T>::push(T data){
		if(currentsize>size){
				cout<<"Overflow\n";
				return;
		}
		StackNode *newnode=new StackNode ;
		currentsize++;
		//newnode->data=data;
		if(currentsize==0){
				newnode->data=data;
				newnode->next=NULL;

				top=newnode;
		}else{

				newnode->data=data;
				newnode->next=top;
				top=newnode;

		}
        //  
}
template <class T>
bool Stack<T>::isEmpty(){
		if (currentsize==0){
				return true;
		}
		else{
				return false;
		}
}
template <class T>
T Stack<T>::pop(){
		if(currentsize==0){
				cout<<"underflow\n";
				return -1;
		}
		int t;
		while(!(isEmpty())){
				StackNode *x;
                x=top;
				t=top->data;
				top=top->next;
				cout<<t<<" "<<endl;

				currentsize--;
                //delete x;
		}
		cout<<endl;
      
		return t;
        

}

template<class T>
class Queue{
		private:
			    //int size;
				Stack<T> *a=new Stack<int>(10);
				Stack<T> *b=new Stack<int>(10);
                Stack<T>stack1;

		public:
				//void enque(T x);
               
    

    void enqueue(T val) {
        if(a->isFull( )){
            cout<<"overflow in queue\n";
            return;
        }else{
            a->push(val);
            
        }
        
       
        
    }
				void deque();
				// Queue(int nsize){
				//		this->size=nsize;
				//} */
				Queue(){}
				~Queue(){}

};
//template<class T>
//void Queue<T>::enque(T x){
    
    /* while(!a.isEmpty()){
        b.push(a.top);
        a.pop();
    } */
    /* if(this->a.isFull()){
        cout<<"Queue is full\n";
    }else */
      /*  cout<<"inside push\n";
       
       this-> a.push(x);
       cout<<"pushing "<<x<<endl;
       cout<<"a.empty \n"<<a.isEmpty()<<endl;
    

}
 */
template<class T>
void Queue<T>::deque(){
    cout<<"inside deque\n";
    //T x;
    ///cout<<"a.pop() "<<stack1.pop()<<endl;
    while(!(this->a->isEmpty())){
        cout<<"After poped into second stack to preserve FIFO property\n";
        
        b->push(a->pop());
		
		 //b->pop();
    }
}

int main(){
	
		cout<<endl;
       
        cout<<"Queue:\n";
        Queue<int>*b=new Queue<int>;
        b->enqueue(1);
        b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
		b->enqueue(176);
       // b.enqueue(90);
    
        b->deque();
        cout<<endl;
   
		

   //cout<<"true\n"<<true<<endl;
}
