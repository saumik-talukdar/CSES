#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

// Define an ordered set using PBDS
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k;
    cin >> n >> k;
    
    ordered_set children;
    vector<int> elimination_order;

    // Initialize the ordered set with all children
    for (int i = 1; i <= n; ++i) {
        children.insert(i);
    }
    
    int index = 0;  // Start from the first child
    while (!children.empty()) {
        // Calculate the index of the child to remove
        index = (index + k) % children.size();
        auto it = children.find_by_order(index);
        
        // Record the elimination order and remove the child
        elimination_order.push_back(*it);
        children.erase(it);
    }
    
    // Output the order of elimination
    for (int child : elimination_order) {
        cout << child << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t=1;
    // Uncomment this if multiple test cases are needed
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
