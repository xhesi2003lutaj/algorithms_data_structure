#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
    string s;
    vector<string>v;
    //Read strings from the keyboard 
    do{
        getline(cin,s);
    //Insert these strings into the vector at the end
       if(s=="END"){
            break;
       }{
         v.push_back(s);
       }
       
    }while (s!="END");
    int i;
  
    if((v.size()<2) || (v.size()<5)){
        cout<<"2nd or/end 5th index not valid\n";
        exit(1);
    }
    swap(v[2],v[5]);
    int n=v.size();
    //Replace the last element with the string “???”.
    v[n-1]="???";
    
    cout<<"Using the index operator\n";
    int ris=v.size();
      for(i=0;i<ris;i++){
        if(i==n-1){
            cout<<v[i]<<endl;
        }else{
            cout<<v[i]<<", ";

        }
    }
    printf("\n");
    vector<string>::iterator t;
    cout<<"Using the iterator\n";
    for(t=v.begin(); t < v.end();t++){
        if(t==(v.end()-1)){
            cout<<*t<<endl;
        }
        else{
             cout<<*t<<", ";
        }
    }
    printf("\n");
    reverse(v.begin(),v.end());

    //eversed order separated by space
    cout<<"Using the iterator and reversed\n";
     for(t=v.begin(); t < v.end();t++){
        if(t==(v.end()-1)){
            cout<<*t<<endl;
        }
        else{
             cout<<*t<<", ";
        }
    }



    return 0;
}