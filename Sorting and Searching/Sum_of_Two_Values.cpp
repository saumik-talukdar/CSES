#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n,x;
    cin>>n>>x;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back({x,i+1});
    }
    sort(v.begin(),v.end());
    int i=0,j=n-1;
    while(i<j){
        if(v[i].first+v[j].first==x){
            int a = v[i].second;
            int b = v[j].second;
            if(a>b)swap(a,b);
            cout<<a<<" "<<b<<endl;
            return;
        }else if(v[i].first+v[j].first>x){
            j--;
        }else{
            i++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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