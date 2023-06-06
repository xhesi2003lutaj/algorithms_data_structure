#include <iostream>
#include<queue>
#include <vector>
# define INF 10000000
using namespace std;

int* d;
int n;
//will be used in priority queue
typedef pair<int, int> intpair;
int find_meetup_city(int** adj_matrix, int your_city, int friend_city);
int sum_of_path(int **adj_matrix, int source, int target);

//finds sum of weights down a path
int sum_of_path(int **adj_matrix, int source, int target)
{
	if(source == target)
		return 0;

	int dist[n];
	//array of predecessors
	int pred[n];
	pred[source] = -1;
	//will keep track of the path
	deque<int> de;

	for(int i = 0; i < n; i++)
		dist[i] = INF;

	priority_queue<intpair, vector<intpair>, greater<intpair>> q;
	q.push(make_pair(0, source));
	dist[source]= 0;
	/*Dijkstra Algorithm*/
	while(!q.empty())
	{
		int node = q.top().second;
		q.pop();
		for(int i = n-1; i>=0; i--)
		{
			int weight = adj_matrix[node][i];
			if((dist[i] > dist[node] + weight) && weight!=0)
			{
				dist[i] = dist[node] + weight;
				pred[i] = node;
				q.push(make_pair(dist[i],i));
			} 
		}
	}
	
	for(int i = pred[target]; i!=source; i = pred[i])
		de.push_front(i);
	de.push_front(source);
	de.push_back(target);
	
	int i = 0, j = (int)de.size()-1;
	int sum=0;
	while(i<j)
	{
		sum+= adj_matrix[de[i]][de[1+(i++)]];
	}
	
	return sum;
}


int find_meetup_city(int** adj_matrix, int your_city, int friend_city)
{
	intpair ip[n];
	for(int i = 0; i<n; i++)
	{
		int a = sum_of_path(adj_matrix, i, your_city);
		int b = sum_of_path(adj_matrix, i, friend_city);
		ip[i].first = i;
		ip[i].second = max(a, b);
	}
	intpair optimal = ip[0];
	for(int i =1; i<n; i++)
	{
		if(ip[i].second < optimal.second)
			optimal = ip[i];
	}

	return optimal.first;
}
int main()
{
	cout<<"Enter n: "<<endl;
	cin >> n;
	int **m, mycity, friendcity;
	m = new int*[n];
	for(int i = 0; i<n; i++)
	{
		m[i] = new int[n];
	}
	cout<<"Enter adj_matrix: "<<endl;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin>>m[i][j];

	cout<<"Enter my city: "<<endl;
	cin >> mycity;

	cout<<"Enter friend city: "<<endl;
	cin >> friendcity;
	
	cout << "The optimal meeting point is : "<<find_meetup_city(m,mycity, friendcity);

	for(int i = 0; i<n; i++)
		delete []m[i];
	delete []m;

	return 0;
}




/* #include<iostream>
#include<queue>
using namespace std;
vector<pair<int, int> > graph[100001];
 
vector<vector<int> > edges;
 
void add_edge(int u, int v, int w)
{
    graph[u].push_back({ v, w });
    graph[v].push_back({ u, w });
    edges.push_back({ u, v, w });
}
 
vector<int> dijsktras(int src, int N)
{
    vector<int> dis(N, INT_MAX);
 
    vector<bool> vis(N, false);
 
    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   greater<pair<int, int> > >
        pq;
    pq.push({ 0, src });
    dis[src] = 0;
 
    while (!pq.empty()) {
 
        auto cur = pq.top();
        pq.pop();
 
        int node = cur.second;
        int weight = cur.first;
 
        if (vis[node])
            continue;
        vis[node] = true;
 
        for (auto child : graph[node]) {
            if (dis[child.first]
                > child.second + weight) {
                dis[child.first] = weight
                                   + child.second;
 
                pq.push({ dis[child.first],
                          child.first });
            }
        }
    }
 
    return dis;
}
 

int shortestDistance(int N, int M,
                     int A, int B)
{

    vector<int> disA = dijsktras(A, N);
 
   
    vector<int> disB = dijsktras(B, N);
 
    int ans = disA[B];
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        int weight = edge[2];
 
        int cur = min(disA[u] + disB[v],
                      disA[v] + disB[u])
                  + (weight / 2);
 
       
        ans = min(ans, cur);
    }
 
    return ans;
}

int main()
{
    int N = 9, M = 14, A = 0, B = 2;
 
  
    add_edge(0, 1, 4);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(3, 4, 9);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(7, 0, 8);
    add_edge(1, 7, 11);
    add_edge(7, 8, 7);
    add_edge(2, 8, 2);
    add_edge(6, 8, 6);
    add_edge(2, 5, 4);
    add_edge(3, 5, 14);
 
    cout <<"Shortest distance is :"<< shortestDistance(N, M, A, B)<<endl;
 
    return 0;
} */