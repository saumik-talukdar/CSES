#include <bits/stdc++.h>
using namespace std;

#define int long long

// Segment tree class
class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int>& hotels) {
        n = hotels.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, hotels);
    }

    // Build the segment tree
    void build(int node, int start, int end, vector<int>& hotels) {
        if (start == end) {
            tree[node] = hotels[start]; // Leaf node holds the number of rooms in a hotel
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, hotels); // Build left child
            build(2 * node + 1, mid + 1, end, hotels); // Build right child
            tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Internal node holds the maximum of its children
        }
    }

    // Query the first hotel that can accommodate rooms >= rooms_needed
    int query(int node, int start, int end, int rooms_needed) {
        if (tree[node] < rooms_needed) {
            return -1; // No hotel in this range can accommodate the group
        }
        if (start == end) {
            return start; // Found the hotel
        }

        int mid = (start + end) / 2;
        if (tree[2 * node] >= rooms_needed) {
            return query(2 * node, start, mid, rooms_needed); // Check left child
        } else {
            return query(2 * node + 1, mid + 1, end, rooms_needed); // Check right child
        }
    }

    // Update the number of rooms in a hotel after assigning
    void update(int node, int start, int end, int idx, int new_value) {
        if (start == end) {
            tree[node] = new_value; // Update the hotel rooms
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, new_value); // Update left child
            } else {
                update(2 * node + 1, mid + 1, end, idx, new_value); // Update right child
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Recompute the max in this range
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> hotels(n);
    for (int i = 0; i < n; ++i) {
        cin >> hotels[i];
    }

    SegmentTree segTree(hotels);

    for (int i = 0; i < m; ++i) {
        int rooms_needed;
        cin >> rooms_needed;

        int hotel_idx = segTree.query(1, 0, n - 1, rooms_needed);
        if (hotel_idx == -1) {
            cout << 0 << " "; // No hotel can accommodate the group
        } else {
            cout << hotel_idx + 1 << " "; // Output the hotel index (1-based)
            hotels[hotel_idx] -= rooms_needed; // Reduce available rooms in the hotel
            segTree.update(1, 0, n - 1, hotel_idx, hotels[hotel_idx]); // Update the segment tree
        }
    }

    cout << endl;

    return 0;
}
