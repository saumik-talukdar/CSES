#include<bits/stdc++.h>
using namespace std;

#define int long long

class SlidingMedian {
    multiset<int> left, right;
    int k;

public:
    SlidingMedian(int k) : k(k) {}

    // Add a new element to the window
    void add(int num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        rebalance();
    }

    // Remove an element from the window
    void remove(int num) {
        if (left.find(num) != left.end()) {
            left.erase(left.find(num));
        } else {
            right.erase(right.find(num));
        }
        rebalance();
    }

    // Rebalance the two sets to maintain the size condition
    void rebalance() {
        // The left part should always have >= right part in terms of size
        if (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        } else if (left.size() < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }

    // Get the median of the current window
    int getMedian() {
        return *left.rbegin();  // Return the largest element in the left set (the median)
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SlidingMedian slidingMedian(k);
    for (int i = 0; i < k; i++) {
        slidingMedian.add(arr[i]);  // Fill the first window
    }

    cout << slidingMedian.getMedian();  // Print the median of the first window

    for (int i = k; i < n; i++) {
        slidingMedian.remove(arr[i - k]);  // Remove the element going out of the window
        slidingMedian.add(arr[i]);         // Add the new element coming into the window
        cout << " " << slidingMedian.getMedian();  // Print the median of the current window
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
// Approach:
// Key Observations:
// A naive approach that sorts each window separately would be too slow for large inputs (O(nk log k) complexity).
// Instead, we can use two data structures (for example, two multisets or two heaps) to maintain the sliding window efficiently and compute the median in O(log k) time for each window.
// Plan:
// Use Two Heaps:
// We maintain two heaps:
// A max heap (left) to store the smaller half of the window elements.
// A min heap (right) to store the larger half of the window elements.
// This way, the largest element of the smaller half will be on top of the max heap, and the smallest element of the larger half will be on top of the min heap.
// Median Calculation:
// If the window has an odd number of elements, the median is the top of the max heap (left).
// If the window has an even number of elements, the median is also the top of the max heap since we are asked to take the smaller of the two middle elements.
// Sliding Window Logic:
// As we slide the window from left to right, we need to:
// Add the new element at the right end of the window.
// Remove the old element at the left end of the window.
// Rebalance the heaps if necessary to maintain the size property (max heap size >= min heap size).
// Efficiency:
// We use O(log k) operations to insert, remove, and rebalance the heaps for each sliding window.
// The total complexity is O(n log k).

// Explanation of the Code:
// SlidingMedian Class:

// The class maintains two multisets left and right, where:
// left holds the smaller half of the elements.
// right holds the larger half of the elements.
// The function add(int num) inserts an element into the appropriate heap.
// The function remove(int num) removes an element from the appropriate heap.
// The function rebalance() ensures that the heaps are balanced in size.
// The function getMedian() returns the median from the current window by returning the largest element in left.
// Main Logic:

// We read the array and initialize a SlidingMedian object.
// For the first k elements, we add them to the window and print the median.
// For the remaining elements, we slide the window by removing the leftmost element (which exits the window) and adding the new element. After each update, we print the median of the current window.
// Time Complexity:
// Each insertion or removal into/from the multiset takes O(log k) time.
// We perform this operation for every element in the array, resulting in an overall complexity of O(n log k), which is efficient enough for n up to 
// 2
// ×
// 1
// 0
// 5
// 2×10 
// 5
//  .