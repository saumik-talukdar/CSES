#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl
const int mod = 1e9+7;

int getWays(int n,vector<int>& dp){
    if(n<0)return 0;
    
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    int x = 0;
    for(int i=1;i<=6;i++){
        x+=getWays(n-i,dp);
    }
    dp[n] = x%mod;
    return x%mod;
}

void solve(){
    // Your code here
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<getWays(n,dp)%mod<<endl;
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