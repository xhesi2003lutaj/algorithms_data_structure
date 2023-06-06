#include<iostream>
#include<cmath>
using namespace std;
int countdig(int arr[],int n){
		int max=arr[0];
		for(int i=0;i<n;i++){
				if(arr[i]>max){
						max=arr[i];
				}
		}
		int count=0;
		while(max%10 != 0){
				count ++;
				max/=10;

		}

		return count;

}
int returnmax(int arr[],int n){
		int max=arr[0];
		for(int i=0;i<n;i++){
				if(arr[i]>max){
						max=arr[i];
				}
		}
		return max;
}
void countsort(int arr[],int n,int po){
		const int siz=10;
		int *b=new int[siz];
		int *output=new int[n];

		memset(b,0,sizeof(*b));

		for(int i=0;i<n;i++){///not <= as it will addd a 1 at the g=begining of the list
				b[(arr[i]/po)%10]++;
				//b[i]/=po;
		}
		for(int i=1;i<siz;i++){///mot <=
				b[i]+=b[i-1];
		}
		for(int i=n-1;i>=0;i--){
				output[b[(arr[i]/po)%10]-1]=arr[i];
				b[(arr[i]/po)%10]--;
		}
		for(int i=0;i<n;i++){
				arr[i]=output[i];
		}
		delete[]output;
		delete []b;
}
void radixsprt(int arr[],int n){
		// int d=countdig(arr,n);
		int d=returnmax(arr,n);
		cout<<"d "<<d<<endl;




		for(int po=1;d/po>0;po*=10){
			cout<<"po "<<po<<endl;
				countsort(arr,n,po);
		}
		/* int i=1;
		   int po=10;
		   while((d/po>0)){
		   int po=pow(10,i);
		   countsort(arr,n,po);        //////////////////////////////////////////////////
		   cout<<"i*10 "<<po<<endl;
		   cout<<"i "<<i<<endl;

		   i*=10;

		   } */
}

int main(){
		double arr[]={118.2,5.98,4987.0,9.8,5.7,3.4,2.7,9798.4,-99.8,9.887,29.87,19.98,23.09};
		int n=sizeof(arr)/sizeof(arr[0]);
        int min=-9787878;
        for(int i=0;i<n;i++){
            int c=abs((arr[i]-int(arr[i])));
            int output=max(c,min);
            min=output;
            
        }
		radixsprt(arr,n);
		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
		int nu=2189;

		cout<<(2189/1000)%10<<endl;
}
