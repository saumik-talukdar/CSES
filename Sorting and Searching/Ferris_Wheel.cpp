#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    // Sort the array to use two-pointer approach
    sort(p.begin(), p.end());
    
    int left = 0, right = n - 1;
    int gondolas = 0;
    
    // Two-pointer technique
    while (left <= right) {
        if (p[left] + p[right] <= x) {
            // Pair the lightest and heaviest child
            left++;
            right--;
        } else {
            // Only the heaviest child goes into a gondola
            right--;
        }
        gondolas++;  // One gondola used
    }
    
    cout << gondolas << endl;
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
