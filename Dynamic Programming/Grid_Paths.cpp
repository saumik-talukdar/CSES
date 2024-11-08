#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl
const int mod = 1e9 +7;

void solve(){
    // Your code here
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            if(ch == '*')v[i][j] = -1;
        }
    }
    if(v[0][0]==-1){
        cout<<0<<endl;
        return;
    }
    v[0][0] = 1;
    for(int j=1;j<n;j++){
        if(v[0][j]==-1){
            v[0][j] =0;
            continue;
        }
        v[0][j] = v[0][j-1];
    }
    for(int j=1;j<n;j++){
        if(v[j][0]==-1){
            v[j][0] =0;
            continue;
        }
        v[j][0] = v[j-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(v[i][j]==-1){
                v[i][j]=0;
                continue;
            }
            v[i][j] = v[i-1][j]+v[i][j-1];
            v[i][j]%=mod;
        }
    }
    cout<<v[n-1][n-1]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}