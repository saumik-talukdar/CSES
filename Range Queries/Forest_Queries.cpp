#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    
    // Forest grid input and prefix sum matrix
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    // Read the forest grid and construct the prefix sum matrix
    for(int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for(int j = 1; j <= n; j++) {
            forest[i][j] = (row[j-1] == '*');
            // Build the prefix sum matrix
            dp[i][j] = forest[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    // Process queries
    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        // Use the inclusion-exclusion principle to calculate the number of trees in the given rectangle
        int result = dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1];
        cout << result << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}
