#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n,x;
    cin>>n>>x;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){

        // two pointer approach
        int j = i+1, k = n-1;
        while(j<k){
            if(v[i].first+v[j].first+v[k].first == x){
                vector<int> ans(3);
                ans[0] = v[i].second+1;
                ans[1] = v[j].second+1;
                ans[2] = v[k].second+1;
                sort(ans.begin(),ans.end());
                cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
                return;
            }else if(v[i].first+v[j].first+v[k].first > x){
                k--;
            }else{
                j++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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