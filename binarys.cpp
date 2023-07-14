


#include<iostream>
using namespace std;
void binarys(int arr[],int n,int l,int h,int &res){
      if(l>h){
            return;
      }
      //int res;
      if(h>=l){
            cout<<"direkt pas if\n";
            int mid =  (h+l) /2;
            if(arr[mid]==n){
                  res= mid;
                  cout<<"mid"<<mid<<endl;
                  cout<<"pas if 1\n";
            }


            else if(arr[mid]>n){
                  binarys(arr,n,l,mid-1,res);
                  cout<<"pas if 2\n";
            }

            else{
                  binarys(arr,n,mid+1,h,res);
            }
            cout<<"last comdition\n";


      }

}

int main(){
      int arr[]={1,2,3,4,5,6,7,8,9,10};
      int n=sizeof(arr)/sizeof(arr[0]);
      cout<<"n "<<n<<endl;
      int res=0;
      binarys(arr,10,0,n-1,res);
      cout<<res<<endl;
}
