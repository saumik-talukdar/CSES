#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
void dfs(int v){
	vis[v]=1;
	//cout<<v<<" -> ";
	for(int child : adj[v]){
		if(!vis[child]){
			dfs(child);
		}
	}
}
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	int n,m;
	cin>>n>>m;
	vis.resize(n+1,0);
	adj.resize(n+1);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    vector<pair<int,int>> edge;
    int curr=1;
	for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
			
            if(i!=curr){
				edge.push_back({i,curr});
            	curr=i;
			}
            //cout << "Component starting at node " << i << ": ";
            dfs(i);
            //cout << "END" << endl;
        }
    }
    cout<<edge.size() << endl;
    for(auto i : edge){
        cout<<i.first << " "<<i.second<<endl;
    }
	return 0;
}
