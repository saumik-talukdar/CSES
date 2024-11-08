#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl
const int mod = 1e9+7;

int getWays(int n,vector<int>& dp,vector<int>& v){
    if(n<0)return 0;
    
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    int x = 0;
    for(int i : v){
        x+=getWays(n-i,dp,v);
    }
    dp[n] = x%mod;
    return x%mod;
}

void solve(){
    // Your code here
    int n,x;
    cin>>n>>x;
    vector<int> dp(x+1,-1),v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<getWays(x,dp,v)%mod<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}