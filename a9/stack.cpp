 #include<iostream>
#include<cstdlib>
using namespace std;
//int count=0;
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
				bool isFull();
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
bool Stack<T>::isFull(){
	
                    if(currentsize>=size){
                        return true;
						
                    }else{
                        return false;
                    }

                
}
template <class T>
T Stack<T>::pop(){
		if(currentsize==0){
				cout<<"underflow\n";
				return -1;
		}
		printf("Popping\n");
		int t;
		while(!(isEmpty())){
				//StackNode *x=top;
				t=top->data;
				top=top->next;
				cout<<t<<" ";

				currentsize--;

		}
		cout<<endl;
		return t;

}

int main(){
		Stack<int> *s=new Stack<int>(4);
		s->push(1);
		s->push(2);
		s->push(3);
    s->push(3);
    s->push(3);
    s->push(3);

	if(s->isFull()){
		cout<<"isful\n";
	}
		s->pop();


		s->pop();
		

		/*    Stack* list=NULL;
			  list->setsize(30);
			  list->push(list,2);
			  list->push(list,23);
			  list->push(list,92);
			  list->printlist(list); */


}
