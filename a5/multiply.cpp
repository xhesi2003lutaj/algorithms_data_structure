#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
/*
 *
 *  Works only for large input 2^n and if strelen(a)==strlen(b);
 *  you cannot cannot call that multiply() function with an argument 2>>65 since there will be an overflow.
 *  2>>65 since there will be an overflow.
 */
int getlength(long long a){
		int count=0;
		while (a!=0){

				count ++;
				a/=10;

		}
		return count;

}

long long multiply(long long a,long long b){
		int n=getlength(a);
		int nb=getlength(b);
		if(n==1 || nb==1 ){
				return a*b;
		}
		else{
				long long  multi=(n/2)+(n%2);
				long long  al=a/multi;
				long long  ar=a-(al*multi);
				long long  bl=b/multi;
				long long br=b-(bl*multi);

				long long x1=multiply(al,bl);
				long long x2=multiply(al+ar,bl+br);
				long long x3=multiply(ar,br);

				return x1*pow(10,n)+(x2-x1-x3)*pow(10,n/2)+x3;
		}

}


int main(){
		long long a,b;
		cin>>a;
		cin>>b;
		cout<<multiply(a,b)<<endl;

}



/* #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(vector<int>v){
for(unsigned int i=0;i<v.size();i++){
cout<<v[i]<<" ";
}
printf("\n");
}

vector<int> multiply(vector<int>a,vector<int>b){

vector<int>res;
reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
unsigned int i=0;
unsigned int j=0;
cout<<"to be multiplied\n";
cout<<"reversed\n";
display(a);
display(b);
if(a.size()>b.size()){
while(j<b.size()){
int prod=a[j]*b[j];
if(prod<10){
res.push_back(prod);
}
else{
res.push_back(prod%10);
res[j+1]=(prod-(prod%10));
}

j++;
}
}if(a.size()<b.size()){
while(i<a.size()){
int prod=a[i]*b[i];
if(prod<10){
res.push_back(prod);
}
else{
res.push_back(prod%10);
res[i+1]=(prod-(prod%10));

}
i++;
}
}
cout<<"result \n";
display(res);
reverse(res.begin(),res.end());
cout<<"result \n";
display(res);
return res;
cout<<endl;
vector<int>res;

for(unsigned int i=0;i<a.size();i++){
res[i]=a[i]*b[i];

}
return res;

}
vector<int> add(vector<int>a,vector<int>b){
vector<int>res;
for(unsigned int i=0;i<a.size();i++){
res[i]=a[i]+b[i];

}
return res;
//std::transform (a.begin(), a.end(), b.begin(), a.begin(), std::plus<int>());
display(a);
}

void devide_and_conquer(vector<int>a,vector<int>b){



		vector<int>left(a.begin(),a.begin()+a.size()/2);
		vector<int>right(a.begin() +a.size()/2, a.end());
		unsigned int i=left.size();
		unsigned int j=right.size();

		while(i<a.size()){
				left.push_back(0);
				i++;
		}
		while(j<b.size()){
				right.push_back(0);
				j++;
		}
		reverse(b.begin(),b.end());
		display(a);
		display(b);
		//vector<int>templ=multiply(left,b);
		cout<<"multiplying: ";
		display(left);display(b);

		//vector<int>tempr=multiply(right,b);
		cout<<"multiplying: ";
		display(right);display(b);

		add(left,b); 
		cout<<"adding: ";
		// display(templ);display(tempr);

		cout<<"result of muktiplication:\n ";
		// display(result);
}

int main(){
		string x,l;
		vector<int> f;
		vector<int> s;
		cin>>x;
		cin>>l;
	  for(unsigned int i=0;i<x.size();i++){
				f.push_back(x[i]-'0');
		}
		for(unsigned i=0;i<l.size();i++){
				s.push_back(l[i]-'0');
		}

		devide_and_conquer(f,s);


		//multiply(f,s);
} */
