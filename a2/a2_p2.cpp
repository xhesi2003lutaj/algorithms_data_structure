#include<iostream>
#include<deque>
using namespace std;
int main(){
		//Create a deque A able to store float values
		deque<float>A;
		float n;
		do{
				cin>>n;
				//Read floats from the keyboard until the value is 0.
				if(n==0){
						break;
				}
				//Insert the positive elements at the end of A and the 
				//negative elements at the beginning of A.
				if(n>0){
						A.push_back(n);
				}else{
						A.push_front(n);
				}


		}while(n!=0);
		for(auto i=A.begin();i!=A.end();i++){
				cout<<*i<<" ";
		}
		printf("\n\n");

		//  deque<float>::iterator it=((A.size())/2);
		int pos=A.size()/2;
		auto it=A.begin();
		it+=pos;
		A.insert(it,1,0);

		for(auto i=A.begin();i<A.end();i++){
				if(i==A.end()-1){
						cout<<*i<<" ";
				}else{
						cout<<*i<<", ";
				}   
		}
		printf("\n");




		return 0;
}
