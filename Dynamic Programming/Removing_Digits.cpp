#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

// Helper function to extract digits of n
vector<int> Digit(int n) {
    vector<int> x;
    while (n) {
        x.push_back(n % 10);
        n /= 10;
    }
    return x;
}

// Recursive function to find minimum steps to reduce n to zero
int getAns(int n, vector<int>& dp) {
    if (n == 0) return 0;       // Base case: 0 steps needed for n = 0
    if (dp[n] != -1) return dp[n]; // Return memoized result if exists

    int minSteps = INT_MAX;
    vector<int> v = Digit(n);    // Get digits of current n
    
    // Explore reducing n by each of its digits
    for (int i : v) {
        if (i != 0) {  // Avoid subtracting 0
            minSteps = min(minSteps, 1 + getAns(n - i, dp));
        }
    }
    
    return dp[n] = minSteps;     // Memoize and return result
}

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);   // Initialize dp array with -1
    cout << getAns(n, dp) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
