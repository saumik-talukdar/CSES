#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<int> vis,v,v2;

int start=0,end=10000000;
bool dfs(int node,int par){
	vis[node]=1;
	v.pb(node);
	for(int child : adj[node]){
		if(!vis[child]){
			if(dfs(child,node))return true;
		}else if(par!=child){
			v.pb(child);
			return true;
		}
	}
	v.pop_back();
	return false;
}
void filterv(){
	bool f=false;
	for(int i : v){
		if(v.back()==i)f=true;
		if(f)v2.push_back(i);
	}
}
signed main(){

	int n,m;
	cin>>n>>m;
	adj.resize(n+1);
	vis.resize(n+1,0);

	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			bool f=true;
			if(dfs(i,-1)){
				filterv();
                cout<<v2.size()<<endl;
				for(int i:v2){
					
					cout<<i<<" ";
				}
				return 0;
			}
		}
	}
    cout<<"IMPOSSIBLE"<<endl;
	return 0;
}