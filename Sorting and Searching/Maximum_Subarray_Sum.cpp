#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl
int max(int x, int y){
    return x>y?x:y;
}
void solve(){
    // Your code here
    int n;
    cin>>n;
    vector<int> v(n),sum(n,0);
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>v[i];
        mx = max(mx,v[i]);
    }
    sum[0] = max(0,v[0]);
    for(int i=1;i<n;i++)sum[i] = max(0,sum[i-1]+v[i]);
    int ans = 0;
    for(int i=0;i<n;i++)ans = max(ans,sum[i]);
    cout<<(ans==0?mx:ans)<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}