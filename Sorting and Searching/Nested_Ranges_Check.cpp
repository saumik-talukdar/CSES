#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;  // stores (x, y, index)

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges.push_back({x, y, i});
    }

    // Sort by starting point x in ascending order, and by y in descending order if x's are the same
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    // Arrays to store the results
    vector<int> contains(n, 0), contained_by(n, 0);

    // Find if each range is contained by another range
    int max_y = LLONG_MIN;
    for (auto &[x, y, idx] : ranges) {
        if (y <= max_y) {
            contained_by[idx] = 1;
        }
        max_y = max(max_y, y);
    }

    // Find if each range contains another range
    int min_y = LLONG_MAX;
    for (int i = n - 1; i >= 0; --i) {
        auto &[x, y, idx] = ranges[i];
        if (y >= min_y) {
            contains[idx] = 1;
        }
        min_y = min(min_y, y);
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << contained_by[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
