#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1000005; // Set the maximum limit
vector<int> v(MAXN, 0);   // Vector to store the divisor counts

void precompute_divisors() {
    // Using a sieve-like approach to count divisors
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            v[j]++; // Increment count for each multiple of i
        }
    }
}

void solve() {
    int x;
    cin >> x;
    cout << v[x] << endl; // Directly print the precomputed result
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precompute_divisors(); // Precompute divisor counts
    int t;
    cin >> t;

    while (t--) {
        solve(); // Solve each query
    }

    return 0;
}
