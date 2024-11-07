#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    stack<pair<int,int>> st; // Stack to store (value, index)
    vector<int> res(n);      // Result array to store the nearest smaller index
    
    for(int i = 0; i < n; i++) {
        // Pop elements from the stack while the current element is smaller or equal
        while(!st.empty() && st.top().first >= arr[i]){
            st.pop();
        }
        
        // If stack is empty, no smaller element exists
        if(st.empty()){
            res[i] = 0;
        } else {
            // The top element is the nearest smaller element
            res[i] = st.top().second;
        }
        
        // Push the current element and its 1-based index to the stack
        st.push({arr[i], i + 1});
    }
    
    // Output the result
    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
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
