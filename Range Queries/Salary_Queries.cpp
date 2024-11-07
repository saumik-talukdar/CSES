#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

// Ordered set as a multiset with pair to handle duplicate values
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    ordered_multiset ms;

    // Insert elements in the multiset as {value, index}
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ms.insert({arr[i], i});  // Insert element with index to handle duplicates
    }

    while (q--) {
        char ch;
        cin >> ch;
        if (ch == '!') {
            int k, x;
            cin >> k >> x;
            k--; // Convert to 0-based index

            int y = arr[k];
            ms.erase(ms.find({y, k}));  // Remove the old value with its index
            ms.insert({x, k});  // Insert the new value with the same index
            arr[k] = x;  // Update the array
        } else {
            int a, b;
            cin >> a >> b;

            // Get the number of elements less than 'a' and 'b + 1'
            int left_count = ms.order_of_key({a, -1});
            int right_count = ms.order_of_key({b + 1, -1});
            
            cout << (right_count - left_count) << endl;  // Number of elements in range [a, b]
        }
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
