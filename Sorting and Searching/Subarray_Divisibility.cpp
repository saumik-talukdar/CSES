#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    arr[0]=0;
    map<int,int> mpp;
    mpp[0]=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
        arr[i]%=n;
        if (arr[i] < 0) arr[i] += n;
        int target=arr[i];
        cnt+=mpp[target];
        mpp[arr[i]]++;
    }
    cout<<cnt<<endl;
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