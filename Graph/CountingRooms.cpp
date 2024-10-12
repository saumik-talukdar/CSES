#include<bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define W(t) int t;cin >> t;while(t--)
#define MOD1 998244353
#define INF 1e18
#define nline "\n"

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
char mat[1001][1001];
int vis[1001][1001]={0};

int dx[]={-1,0,1,0,-1,1,-1,1};
int dy[]={0,1,0,-1,-1,-1,1,1};
int N,M;

bool isValid(int x,int y){

	if(x<1 || x>N || y<1 || y>M) return false;

	if(vis[x][y] || mat[x][y]=='#')return false;
	
	return true;
}

void bfs(int srcX,int srcY){

	vis[srcX][srcY]=1;
	queue<pair<int,int>> q;
	q.push({srcX,srcY});

	while(!q.empty()){
		int currX=q.front().first;
		int currY=q.front().second;
		q.pop();

		// 4 for side
		// 8 for side+corner
		for(int i=0;i<4;i++){
			if( isValid(currX+dx[i],currY+dy[i]) ){
				int newX=currX+dx[i];
				int newY=currY+dy[i];
				vis[newX][newY]=1;
				q.push({newX,newY});
			}
		}
	}
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>mat[i][j];
        }
    }
    int cc=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(mat[i][j]=='#')continue;
            if(vis[i][j])continue;
            bfs(i,j);
            cc++;
        }
    }
    cout<<cc<<endl;

    return 0;
}