#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n;
    cin>>n;
    vector<int> departure;
    vector<int> arrival;
    vector<int> points;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arrival.push_back(x);
        departure.push_back(y);
        points.push_back(x);
        points.push_back(y);
    }
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    sort(points.begin(),points.end());
    vector<int> res;
    int ans = 0;
    for(int i : points){
        int x = upper_bound(arrival.begin(),arrival.end(),i) - arrival.begin();
        int y = upper_bound(departure.begin(),departure.end(),i) - departure.begin();
        x--,y--;
        if(arrival[x]==i){
            res.push_back(1);
        }else{
            res.push_back(-1);
        }
    }
    for(int i=1; i<res.size(); i++)res[i]+=res[i-1];
    for(int i=0; i<res.size(); i++)ans = max(ans,res[i]);
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