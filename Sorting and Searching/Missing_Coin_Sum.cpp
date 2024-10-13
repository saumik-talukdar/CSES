#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // Step 1: Sort the coins in ascending order
    sort(coins.begin(), coins.end());
    
    // Step 2: Initialize the smallest unformable sum
    int smallest_sum = 1;
    
    // Step 3: Traverse through the coins
    for(int i = 0; i < n; i++) {
        // If the current coin is greater than the smallest sum we can't form, we stop
        if(coins[i] > smallest_sum) {
            break;
        }
        // Otherwise, we can now form sums up to (smallest_sum + coins[i] - 1)
        smallest_sum += coins[i];
    }
    
    // Step 4: Output the result
    cout << smallest_sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
