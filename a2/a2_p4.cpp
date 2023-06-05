#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
		vector<int>vec;
		//Write a program which fills a vector with the integer values from 1 to 30
		for(int i=0;i<=30;i++){
				vec.push_back(i);
		}
		//Then add the value 5 at the end of the vector. Reverse the vector
		vec.push_back(5);

		reverse(vec.begin(),vec.end());
		vector<int>::iterator itt=vec.begin();
		printf("\nReversing 5 ... ");
		while (itt!=vec.end())
		{
				cout<<*itt<<" ";
				itt++;
		}
		printf("\n");
		replace(vec.begin(),vec.end(),5,129);
		vector<int>::iterator it=vec.begin();
		printf("\nReplacin 5 ... ");
		while (it!=vec.end())
		{
				cout<<*it<<" ";
				it++;
		}

		printf("\n");
		return 0;
}
