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

vector<string> q(8);
vector<vector<int>> filling(8,vector<int>(8,0));
void input(){
    for(int i=0;i<8;i++) cin>>q[i];
}
void init_filling(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(q[i][j]=='*')filling[i][j]=1;
        }
    }
}
void update_filling(int row,int col,int val){
    for(int i=0;i<8;i++) filling[row][i]=val;
    for(int i=0;i<8;i++) filling[i][col]=val;

    for(int i=0;i<8;i++){
        if(row+i <8 && col+i <8){
            filling[row + i][col + i] = val;
        }

        if(row+i < 8 && col-i >= 0){
            filling[row + i][col - i] = val;
        }

        if(row-i >=0 && col-i >= 0){
            filling[row - i][col - i] = val;
        }

        if(row-i >=0 && col+i <8){
            filling[row - i][col + i] = val;
        }
    }
    init_filling();

}

int rec(int row){

    if(row == 8) return 1;
    int s=0;
    vector<vector<int>> filling_back=filling;
    for(int i=0;i<8;i++){
        if(q[row][i]=='*')continue;
        if(filling[row][i]==1)continue;
        update_filling(row,i,1);
        s+=rec(row+1);
        filling=filling_back;
    }
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    input();
    init_filling();
    int a=rec(0);
    cout<<a<<endl;
    return 0;
}