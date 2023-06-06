#include<iostream>
using namespace std;

void printarr(int arr[],int n);
void selection_sort(int arr[],int n){
		int i=0;
        cout<<"\n   The SekectionSort is correct as after every iteration the"; 
        cout<<"left hand side";
        cout<<"\n   of the array consists of elements in sorted order according";
        cout<<"to the condition"<<endl;
        cout<<"   The subarray A[1...N-1] consists of elements originally in";
        cout<<"A[1...N-1 ],"<<endl;
        cout<<"   but in sorted oderd\n";
        cout<<"      {\n";
		while(i<n-1){
				cout<<"i in while "<<i<<endl;
				int minidx=i;
				int j;
				for(j=i+1;j<n;j++){
                    cout<<"i in for "<<i<<endl;
                    cout<<"j in for "<<j<<endl;
						if(arr[j]<arr[minidx]){
								minidx=j;
						}
				}
                int temp=arr[i];
				arr[i]=arr[minidx];
				arr[minidx]=temp;
				printarr(arr,n);
				i++;
		}
        cout<<"        }\n";
}

void printarr(int arr[],int n){

		for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
		}
		cout<<endl;
}
int main(){

		
        cout<<"Input the elements you want to sort ";
        int n;
        cin>>n;
        int arr[n];
        int i=0;
        while(n--){

            arr[i]=(47+rand() % 2);

            i++;

        }

        int size=sizeof(arr)/sizeof(arr[0]);
        printarr(arr,size);
        
        selection_sort(arr,size);
		


		return 0;
}
