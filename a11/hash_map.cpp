#include<iostream>
using namespace std;
/*
 * a good hash function can be produced by the remainder method or the multiplication method, below is used the remainder one
 */
#define maxSize 5
class Node {
		public:

				int key;
				int value;
				Node(){}
				Node(int key, int value){
						this->key=0;
						this->value=0;

				}
};
class HashTable {


		private:
				Node **arr;

				int currentSize;
		public:
				HashTable(){

						this->currentSize=0;
						this->arr=new Node*[maxSize];
						for(int i=0;i<maxSize;i++){ 
								arr[i] = new Node();
								arr[i]->value=-1;
						} 
				}
				int hashCode1(int key){
						return key %maxSize;

				}
				void insertNode(int key, int value){
						int idx=hashCode1(value);
						if(this->arr[idx]->value!=-1){
								int i=1;
								while(1){
										int x=(hashCode1(key)+i)%maxSize;
										if(arr[x]->value==-1){
												arr[x]->value=value;
												break;
										}
										i++;
								}

						}else{
								arr[idx]->value=value;
						}
						currentSize++;

				}
				int get(int key){
						int idx=hashCode1(key);
						return arr[idx]->value;
				}
				bool isEmpty(){
						if(currentSize==0){
								return true;
						}
						return false;
				}
				void printdata(){
						/* int idex=hashCode1(key);
						   for(int i=0;i<maxSize;i++){
						   if(arr[i]->key!=idex){
						   cout<<"this elemnet is not in the table\n";
						   return;
						   }

						   } */
						for(int i=0;i<maxSize;i++){
								cout<<i<<"--->"<<arr[i]->value<<endl;
						}


				}
};

int main(){
		HashTable b;

		b.insertNode(1,26);
		b.insertNode(10,26);
		b.insertNode(2,26);
		b.insertNode(4,26);
		//b.insertNode(5,26);
		b.printdata();
		if(b.isEmpty()){
				cout<<"is empty\n"<<endl;
		}
		else{
				cout<<"is not empty"<<endl;
		}
		cout<<"geting element by key\n";
		cout<<b.get(1)<<endl;
		return 0;
}
