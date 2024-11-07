#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sliding window variables
    unordered_map<int, int> freq;  // To count frequency of each element in the window
    int l = 0;  // Left pointer of the window
    int distinct = 0;  // Number of distinct elements in the window
    int result = 0;  // To store the total count of subarrays

    for (int r = 0; r < n; r++) {
        // Add arr[r] to the window
        if (freq[arr[r]] == 0) {
            distinct++;  // New distinct element
        }
        freq[arr[r]]++;

        // Shrink the window if there are more than k distinct elements
        while (distinct > k) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) {
                distinct--;  // Element no longer in the window
            }
            l++;  // Move the left pointer to the right
        }

        // The number of valid subarrays that end at index r is (r - l + 1)
        result += (r - l + 1);
    }

    cout << result << endl;
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
