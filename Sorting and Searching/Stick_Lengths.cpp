#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> sticks(n);
    
    for(int i = 0; i < n; i++){
        cin >> sticks[i];
    }
    
    // Step 1: Sort the stick lengths
    sort(sticks.begin(), sticks.end());
    
    // Step 2: Find the median
    int median = sticks[n / 2];
    
    // Step 3: Calculate the total cost
    int total_cost = 0;
    for(int i = 0; i < n; i++){
        total_cost += abs(sticks[i] - median);
    }
    
    // Step 4: Output the total cost
    cout << total_cost << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
