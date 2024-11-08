#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl

// Recursive function with memoization
int minElements(vector<int>& v, int x, vector<int>& memo) {
    if (x == 0) return 0;          // Base case: If the target is zero, no elements are needed
    if (x < 0) return INT_MAX;      // If x goes negative, it's not possible to form the sum
    if (memo[x] != -1) return memo[x]; // Check memo table to avoid recomputation

    int minCount = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        int result = minElements(v, x - v[i], memo); // Recursive call reducing the target by v[i]
        if (result != INT_MAX) { // Only update if result is valid
            minCount = min(minCount, result + 1); // Add 1 to account for this element
        }
    }

    memo[x] = minCount; // Store result in memo table
    return memo[x];
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }


    // Memoization table initialized to -1
    vector<int> memo(x + 1, -1);

    int result = minElements(v, x, memo);
    if (result != INT_MAX) {
        cout << result << endl;  // Minimum elements needed to achieve sum x
    } else {
        cout << -1 << endl;  // If sum x cannot be achieved
    }



    // vector<int> dp(x + 1, INT_MAX);  // DP array to store minimum count to achieve each sum up to x
    // dp[0] = 0; // base case, no element needed to make sum 0

    // // Iterative DP approach
    // for (int i = 1; i <= x; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i >= v[j] && dp[i - v[j]] != INT_MAX) {
    //             dp[i] = min(dp[i], dp[i - v[j]] + 1);
    //         }
    //     }
    // }

    // // Output the result for dp[x]
    // if (dp[x] != INT_MAX) {
    //     cout << dp[x] << endl;  // Minimum elements needed to achieve sum x
    // } else {
    //     cout << -1 << endl;  // If sum x cannot be achieved
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
