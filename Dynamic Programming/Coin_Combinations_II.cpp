#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // DP array to store the number of unique combinations for each sum up to x
    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make sum 0 (using no coins)

    // Fill dp array
    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    // Output the number of ways to form sum x
    cout << dp[x] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
