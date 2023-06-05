#include<iostream>
#include<set>
#include<cstdlib>
using namespace std;

int main(){
		set<int>a;
		int t=6;
		srand(time(NULL));
		// srand(static_cast<unsigned int>(time(0)));
		while (t--)
		{
				int random=(rand() % 49+1);
				//add the drawn number to a container that stores all drawn numbers 
				a.insert(random);
		}
		set<int>::iterator it;
		//print them on the standard output in ascending order
		for( it=a.begin();it!=a.end();it++){
				cout<<*it<<" ";
		}
		printf("\n");
		return 0;
}
