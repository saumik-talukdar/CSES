
// Notes: well this is accepted solution and complexity is O(n log n) , but
// we should try to solve it using binary search
// need to try that also

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    // Your code here
    int n;
    cin>>n;
    multiset<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(st.empty()){
            st.insert(x);
        }else{
            auto it = st.upper_bound(x);
            if(it==st.end()){
                st.insert(x);
            }else{
                st.erase(it);
                st.insert(x);
            }
        }
    }
    cout<<st.size()<<endl;
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