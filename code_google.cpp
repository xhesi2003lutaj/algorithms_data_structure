#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int m,R,n;
    cin>>m>>R>>n;
    int a[n];
    vector<int> v(m+1, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        v[a[i]]=1;
    }
    int l=0, r=0;
    int ans=0;
    while (r<m){
        if(r==0)
            r=l+R;
        else
            r=l+2*R;
        cout<<"l: "<<l<<" r: "<<r<<endl;
        for(int i=r; i>=l-1; i--){/////
            if(v[i]==1){
                l=min(m,i+R);
                ans++;
                break;
            }
            if (i==l){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    cout<<ans<<endl;
}
int main() {
    int t=1;
    cin>>t;
    int testcase=t;
    while(t--){
        cout<<"Case #"<<testcase-t<<": ";
        solve();
    }
    return 0;
}