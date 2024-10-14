#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n,x;
    cin>>n>>x;
    map<int,int> mpp;
    int sum = 0;
    int ans = 0;
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
        mpp[sum]++;
        ans+=mpp[sum-x];
    }
    cout<<ans<<endl;
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