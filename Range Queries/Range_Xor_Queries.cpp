#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    arr[0] = 0;
    for(int i=1;i<=n;i++)cin>>arr[i],arr[i]^=arr[i-1];
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(arr[r]^arr[l-1])<<endl;
    }
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