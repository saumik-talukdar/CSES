#include<bits/stdc++.h>
using namespace std;

#define int long long

bool canDivide(vector<int>& arr, int n, int k, int maxSum) {
    int currentSum = 0, subarrayCount = 1;  // Start with one subarray
    for (int i = 0; i < n; i++) {
        if (currentSum + arr[i] > maxSum) {
            // If adding arr[i] exceeds maxSum, start a new subarray
            subarrayCount++;
            currentSum = arr[i];
            if (subarrayCount > k) {
                return false;  // Too many subarrays
            }
        } else {
            currentSum += arr[i];
        }
    }
    return true;  // We could divide the array into <= k subarrays
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int maxElement = 0, totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]);
        totalSum += arr[i];
    }
    
    // Binary search on the maximum sum in subarray
    int low = maxElement, high = totalSum, result = totalSum;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canDivide(arr, n, k, mid)) {
            result = mid;  // Try to minimize the max sum
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << result << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
