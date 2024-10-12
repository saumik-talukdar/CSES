#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

// Segment tree with lazy propagation
class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    // Build the segment tree
    void build(vector<int>& arr, int index, int l, int r) {
        if (l == r) {
            tree[index] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * index + 1, l, mid);
            build(arr, 2 * index + 2, mid + 1, r);
            tree[index] = tree[2 * index + 1] + tree[2 * index + 2];  // Sum for range
        }
    }

    // Apply pending updates to the current node
    void propagate(int index, int l, int r) {
        if (lazy[index] != 0) {
            tree[index] += lazy[index] * (r - l + 1);  // Apply the pending update
            if (l != r) {
                lazy[2 * index + 1] += lazy[index];  // Propagate to left child
                lazy[2 * index + 2] += lazy[index];  // Propagate to right child
            }
            lazy[index] = 0;  // Clear the lazy value for the current node
        }
    }

    // Range update: increment values in range [ql, qr] by value
    void updateRange(int ql, int qr, int value, int index, int l, int r) {
        propagate(index, l, r);
        if (l > qr || r < ql) return;  // No overlap

        if (l >= ql && r <= qr) {  // Complete overlap
            lazy[index] += value;
            propagate(index, l, r);
            return;
        }

        // Partial overlap
        int mid = (l + r) / 2;
        updateRange(ql, qr, value, 2 * index + 1, l, mid);
        updateRange(ql, qr, value, 2 * index + 2, mid + 1, r);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    // Point query: get value at position pos
    int queryPoint(int pos, int index, int l, int r) {
        propagate(index, l, r);
        if (l == r) return tree[index];  // Found the position

        int mid = (l + r) / 2;
        if (pos <= mid) return queryPoint(pos, 2 * index + 1, l, mid);
        else return queryPoint(pos, 2 * index + 2, mid + 1, r);
    }

    // Public interface for range update
    void update(int ql, int qr, int value) {
        updateRange(ql, qr, value, 0, 0, n - 1);
    }

    // Public interface for point query
    int query(int pos) {
        return queryPoint(pos, 0, 0, n - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    SegmentTree segTree(arr);
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // Range update: increment elements in range [a, b] by u
            int a, b, u;
            cin >> a >> b >> u;
            a--, b--;  // Convert to 0-based indexing
            segTree.update(a, b, u);
        } else if (type == 2) {
            // Point query: get value at position k
            int k;
            cin >> k;
            k--;  // Convert to 0-based indexing
            cout << segTree.query(k) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
