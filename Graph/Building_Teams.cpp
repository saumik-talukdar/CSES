#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ar;
vector<int> vis,col;
bool dfs(int v,int c){
	vis[v]=1;
	col[v]=c;

	for(int child : ar[v]){
		if(!vis[child]){
			if(!dfs(child,c^1))return false;
		}else{
			if(col[v]==col[child])return false;
		}
	}
	return true;
}
bool isBipartite(int n){
	for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if(!dfs(i,0)){
            	return false;
            }
        }
    }
    return true;
}
signed main(){
	int n,m;
	cin>>n>>m;
	vis.resize(n+1,0);
	ar.resize(n+1);
	col.resize(n+1,-1);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ar[x].push_back(y);
		ar[y].push_back(x);
	}
	
    if (isBipartite(n)) {
        //cout << "The graph is bipartite." << endl;
        for(int i=1;i<=n;i++)cout<<col[i]+1<<" ";
    } else {
        //cout << "The graph is not bipartite." << endl;
        cout<<"IMPOSSIBLE"<<endl;
    }
	return 0;
}
