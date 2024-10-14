#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve() {
    int n;
    cin >> n;
    
    // Use a queue to simulate the circular arrangement
    queue<int> q;
    
    // Initialize the queue with children numbered 1 to n
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    q.pop();
    q.push(1);
    vector<int> removalOrder; // To store the order of removal

    // While there are children in the queue
    while (!q.empty()) {
        // Remove the first child and save the order
        int current = q.front();
        q.pop(); // Remove the child
        removalOrder.push_back(current); // Record the removal order

        // Remove the next child (if exists)
        if (!q.empty()) {
            int next = q.front();
            q.pop(); // Remove the next child
            q.push(next); // Put the next child at the end of the queue
        }
    }

    // Print the removal order
    for (int i : removalOrder) {
        cout << i << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; // You can modify this to handle multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
