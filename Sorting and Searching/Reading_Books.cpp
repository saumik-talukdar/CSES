#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> books(n);
    int total_time = 0, max_time = 0;

    for (int i = 0; i < n; ++i) {
        cin >> books[i];
        total_time += books[i];
        max_time = max(max_time, books[i]);
    }

    // The minimum total time is the maximum of two values:
    // 1. The total time if both read all books sequentially (i.e., total_time)
    // 2. Twice the time of the longest book (i.e., 2 * max_time)
    cout << max(total_time, 2 * max_time) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
