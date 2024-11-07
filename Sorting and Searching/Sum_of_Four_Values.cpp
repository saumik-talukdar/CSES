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
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i;
        tmp[i]=v[i].first;
    }
    sort(v.begin(),v.end());
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<n;i++){
        int m = upper_bound(tmp.begin(),tmp.end(),(x-tmp[i])) - tmp.begin();
        for(int j=i+1;j<m;j++){
            if(tmp[i]+tmp[j]>=x)break;
            int start = j+1;
            int end =upper_bound(tmp.begin(),tmp.end(),(x-tmp[i]-tmp[j])) - tmp.begin();
            end--;
            while(start<end){
                if(tmp[i]+tmp[j]+tmp[start]+tmp[end]==x){
                    vector<int> ans(4);
                    ans[0] = v[i].second+1;
                    ans[1] = v[j].second+1;
                    ans[2] = v[start].second+1;
                    ans[3] = v[end].second+1;
                    sort(ans.begin(),ans.end());
                    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
                    return;
                }else if(tmp[i]+tmp[j]+tmp[start]+tmp[end]>x){
                    end--;
                }else{
                    start++;
                }
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