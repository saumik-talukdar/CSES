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
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    W(t){
        ll x,y;
        cin>>y>>x;
        ll result = 0;
        // if(x==1 && y==1){
        //     cout<<1<<endl;
        //     continue;
        // }
        if(x>y){
            
            ll sq=x*x;
            ll sq2=(x-1)*(x-1);
            if(x&1){
                result=sq-y+1;
            }else{
                result=sq2+y;
            }
        }else{
            
            ll sq = y * y;
            ll sq2 = (y - 1) * (y - 1);
            if (y&1)
            {
                result = sq2 + x;
            }
            else
            {
                result = sq - x +1;
            }
        }
        cout<<result<<endl;

    }
    return 0;
}