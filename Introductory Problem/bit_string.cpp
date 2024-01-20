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

ll result=0;
ll bin_expo(ll x){
    if(x<30){
        ll tmp= pow(2,x);
        tmp=tmp%MOD;
        return tmp;
    }
    ll tmp=1;
    if(x&1){
        tmp=tmp*2;
        x--;
    }
    ll m = bin_expo(x / 2)%MOD;
        tmp = ((tmp % MOD) * ((m*m)%MOD)) % MOD;
    return tmp;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    cout<<bin_expo(n)<<endl;
    return 0;
}