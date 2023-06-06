/*
*  the solution with not just sorting is down, but it will work under certain constraint 
in the overlaping of the scedules, that's why i put it in commments 
*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
struct activity{
		int start,finsh;
};
bool compare(activity a,activity b){
		return a.start>b.start;
}
void activity_selection(vector<activity>s){

		sort(s.begin(),s.end(),compare);
		unordered_set<int>res;
		//sort(s.begin(),s.end(),[](auto const& a,auto const& b){return a.start>b.start};);
		int k=0;
		cout<<s[0].start<<" "<<s[0].finsh<<endl;
		for(int i=1;i<s.size();i++){
				if(s[k].start>=s[i].finsh){
						//cout<<s[i].start<<" "<<s[i].finsh<<endl;
						res.insert(i);
						k=i;
				}
		}
		for(auto i:res){
				cout<<s[i].start<<" "<<s[i].finsh<<endl;
		}
}
int main(){
		vector<activity>b={
				{9,12},{4,5},{2,8},{0,2},{1,4},{3,7},{11,12},{5,6}
		};
		activity_selection(b);
}

/* #include <iostream>
#include <vector>
using namespace std;

struct A{
    int startTime;
    int finishTime;
};

vector <A> ActivitySelection(vector <A> S){

    vector<A> ActivitySolution; 
    int LST;
    int index;

    while (!S.empty()) {
        LST = 0;
        for (int i = 0; i < S.size(); i++){
            if (S[i].startTime > LST){
                LST = S[i].startTime;
                index = i;
            }
        }

        int x = 0;
        for (int i = 0; i < ActivitySolution.size(); i++){
            if (S[index].finishTime > ActivitySolution[i].startTime){
                x++;
            }
        }
        if (x == 0){
            ActivitySolution.push_back(S[index]);
        }
        S.erase(S.begin() + index);
    }
    return ActivitySolution;
}

int main() {
    
    vector <A> S;
    S = {{6, 7}, {6, 13},{1, 12}, {4, 5},{7, 9}, {1, 3}};
    S = ActivitySelection(S);
    int n = S.size();

    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1<< ":" << endl;
        cout << S[i].startTime << " " << S[i].finishTime << endl << endl;
    }
    return 0;
} */
