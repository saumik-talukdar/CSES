#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n;
    cin>>n;
    int arr[n];
    vector<int> prev(n,-1);
    map<int,int> prev_cnt;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(prev_cnt.find(arr[i])==prev_cnt.end()){
            prev_cnt[arr[i]] = i;
        }else{
            prev[i] = prev_cnt[arr[i]];
            prev_cnt[arr[i]] = i;
        }
    }
    int start=0,end=0;
    int mx=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(prev[i]<start){
            cnt++;
        }else{
            mx = max(mx, end-start);
            start = prev[i]+1;
        }
        end++;
    }
    mx = max(mx, end-start);
    cout<<mx<<endl;
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