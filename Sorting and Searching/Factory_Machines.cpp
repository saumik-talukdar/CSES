#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    // Binary search for the minimum time required
    int low = 1, high = *max_element(machines.begin(), machines.end()) * t;
    int answer = high;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int total_products = 0;
        
        // Calculate total products that can be produced in 'mid' time
        for (int i = 0; i < n; ++i) {
            total_products += mid / machines[i];
            if (total_products >= t) break; // early exit if already enough products
        }
        
        if (total_products >= t) {
            answer = mid; // this time works, try to minimize
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
