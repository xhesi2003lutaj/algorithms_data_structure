#include<iostream>
#include<fstream>
#include<cassert>
#include<map>
#include<iterator>
using namespace std;

int main(){
		ifstream read;
		read.open("data.txt");
		//Write a program which creates a collection of names and b.dates
		map<string,string>form;
		assert(read);
		while(!read.eof()){

				//read the content of the file and use a map to store 
				string name; string bday;
				getline(read,name);
				getline(read,bday);
			

				form.insert(pair<string,string>(name,bday));


		}

		map<string,string>::iterator it;
		 for(it=form.begin();it!=form.end();it++){
				cout<<it->first<<endl;
				/*cout<<it->second<<endl;*/
		} 
	
		cout<<"enter a name whose bday you wanna know: ";
		string input;
		getline(cin,input);
		for(const auto& [key,value]:form){
				if(input!=key){
						cout<<"not found"<<endl;
						//	break;
				}
				if(input==key){
						cout<<"["<<value<<"]"<<endl;
						break;

				}

		}

		/* 	if(form[input].empty()){
			cout<<"Name not found!"<<endl;
			}else{
			cout<<"["<<input<<"]"<<endl;
			cout<<form[input]<<endl;
			}
		 */





		return 0;
}
