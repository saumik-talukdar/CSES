#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl


void solve(){
    // Your code here
    int n,m;
    cin>>n>>m;
    multiset<int> v;
    vector<bool> taken(n,false);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.emplace(x);
    }
    while(m--){
        int x;
        cin>>x;
        auto it = v.upper_bound(x);
        
        if(it == v.begin()){
            cout<<-1<<endl;
        }else{
            it--;
            cout<<*it<<endl;
            v.erase(it);
        }
    }
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