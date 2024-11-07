#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

// Ordered set with indexing
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;

    vector<int> elements(n);  // Original list of elements
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    vector<int> positions(n);  // Positions to remove in sequence
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    ordered_set os;  // Ordered set to store elements with original indices
    for (int i = 0; i < n; i++) {
        os.insert({i, elements[i]});  // Insert with (index, value)
    }

    vector<int> result;

    // Process each removal position
    for (int i = 0; i < n; i++) {
        int pos = positions[i] - 1;  // Convert to 0-based index
        auto it = os.find_by_order(pos);  // Get the pos-th element

        int removedElement = it->second;  // The element value at this position
        result.push_back(removedElement);  // Store in result

        os.erase(it);  // Remove this element from the set
    }

    // Output the removed elements in order
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
