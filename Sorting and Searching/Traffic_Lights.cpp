#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int x,n;
    cin>>x>>n;
    multiset<int> gap,ms;
    ms.insert(0);
    ms.insert(x);
    gap.insert(x);
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        auto it = ms.upper_bound(p);
        auto it2 = it;
        it2--;
        int p1 = *it - *it2;
        //cout<<*it<<" "<<*it2<<endl;
        auto it3 = gap.lower_bound(p1);
        gap.erase(it3);
        gap.insert(p-*it2);
        gap.insert(*it - p);
        ms.insert(p);
        auto it4 = gap.end();
        it4--;
        cout<<*it4<<" ";
    }
    cout<<endl;
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