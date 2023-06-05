#include<iostream>
#include <list>
#include<fstream>
#include<vector>
using namespace std;

void simp_print(list<int>x){
		printf("Simple print fs: ");
		while(!x.empty()){
				cout<<x.front();
				x.pop_front();
				if(!x.empty()){
						cout<<", ";
				}
		}
		cout<<endl;
}

void printlist(list<int>x){
		printf("Using the iterator: ");
		list<int>::iterator it;
		for( it=x.begin();it!=x.end();it++){
				cout<<*it<<" ";
		}
		cout<<"\n";
}

void sort_print(list<int>t){
		t.sort();
		printf("Merged and sorted:\n");
		while (!t.empty())
		{
				cout<<t.front()<<" ";
				t.pop_front();
		}
		printf("\n");

}

//Move the first element of the lists to the end (for both lists)
void swapels(list<int>s){
		printf("Moved: ");
		// replace(s.front(),s.back());
		//  s.push_back(s.front());
		s.splice(s.end(),s,s.begin());
		simp_print(s);
		printf("\n");
}

int main(){
		//Create two lists (A and B)
		list<int> A,B;
		int n;
		do{
				cin>>n;
				if(n<0){
						break;
				}
				//insert the positive integers into list A by adding to the end
				A.push_back(n);
				//Insert into list B by adding to the beginning
				B.push_front(n);

		}while (n>0);  
		simp_print(A);


		ofstream myfile;
		myfile.open("listB.txt");
		list<int>::iterator it;
		if(!myfile.is_open()){
				cout<<"error opening the file\n"<<endl;
		}else{
				for( it=B.begin();it!=B.end();it++){
						myfile<<*it<<" ";
				}
		}
		cout<<"\n";

		swapels(A);
		swapels(B);

		printlist(A); 
		printlist(B);

		printf("\n");
		//Merge list B into list A
		A.merge(B);
		sort_print(A);

		myfile.close();
		return 0;
}
