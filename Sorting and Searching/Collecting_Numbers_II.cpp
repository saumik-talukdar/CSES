#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Track the position of elements
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[arr[i]] = i;
    }

    // Calculate initial number of rounds
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i + 1] < pos[i]) {
            rounds++;
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;  // 0-based indexing

        // Get the values at positions a and b
        int valA = arr[a], valB = arr[b];

        // Track the set of numbers affected by the swap (before and after the swap)
        set<int> affected;
        affected.insert(valA);
        affected.insert(valB);
        if (valA > 1) affected.insert(valA - 1);
        if (valA < n) affected.insert(valA + 1);
        if (valB > 1) affected.insert(valB - 1);
        if (valB < n) affected.insert(valB + 1);

        // Remove the effect of the affected numbers before the swap
        for (int x : affected) {
            if (x > 1 && pos[x] < pos[x - 1]) rounds--;
        }

        // Perform the swap in the array and update positions
        swap(arr[a], arr[b]);
        swap(pos[valA], pos[valB]);

        // Add the effect of the affected numbers after the swap
        for (int x : affected) {
            if (x > 1 && pos[x] < pos[x - 1]) rounds++;
        }

        // Output the current number of rounds after the swap
        cout << rounds << endl;
    }
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
