
#include <iostream>

using namespace std;
void max_heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if( i!=largest){
        swap(arr[i],arr[largest]);

        max_heapify(arr,n,largest);
    }

}
void heapsort(int arr[], int n){
    for(int i=n/2;i>=0;i--){
        max_heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);

        max_heapify(arr,i,0);

    }
}
void printarray(int arr[],int n){
    int i=0;
    cout<<"printing array ";
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }

    cout<<endl;
    cout<<endl;
}

int exract_max(int arr[],int &n){
    int max;
    if(n<1){
        cout<<"underflow"<<endl;
        return -1;
    }
      max_heapify(arr,n,0);
        max=arr[0];
        arr[0]=arr[n-1];
        n-=1;
       max_heapify(arr,n,0); 
        
    
    return max;
    
}

void increase_key(int arr[],int i,int key,int &n){
    if(key<arr[i]){
        cout<<"wrog operation\n";
        return;
    }
    arr[i]=key;
   
    heapsort(arr,n);
   //  while(i>0 && arr[i/2]<arr[i]){
     //   swap(arr[i],arr[i/2]);                      not working
       // i=i/2;
    //} 
}
void insert_el(int arr[],int key,int n){
    if(n<1){
       
    arr[n]=key;
     n=n+1;
    }
    else{
    arr[n]=key;
     n=n+1;
     heapsort(arr,n);
    }
    
    //int i=n-1;
    printf("mrena insert\n");
    
    
    
}

int main()
{
   int arr[]={4,5,7,3,2,1,0,7,2,9};
   int n=sizeof(arr)/sizeof(int); 
   cout<<"max \n"<<exract_max(arr,n)<<endl;      //filling with zeros after exract
   cout<<"max \n"<<exract_max(arr,n)<<endl;  
   
   cout<<"extracting\n";
   
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;

   
   heapsort(arr,n);

   printarray(arr,n);

   cout<<"insreasing key\n";
   increase_key(arr,12,1,n);
   printarray(arr,n);

   cout<<"inserting\n";
   insert_el(arr,6,n);                  //works but gives a segmentation fault after printing
   
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;

}
