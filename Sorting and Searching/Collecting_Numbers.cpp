#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pos(n + 1);  // Store the position of each element in the array
    
    // Read the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;  // Store the position of each element
    }
    
    int rounds = 1;  // At least 1 round is required
    for (int i = 2; i <= n; i++) {
        // If the current number is placed after the previous one in the array
        if (pos[i] < pos[i - 1]) {
            rounds++;  // Start a new round
        }
    }
    
    cout << rounds << endl;
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
