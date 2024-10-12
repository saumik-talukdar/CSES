#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

// Function to build the segment tree
void build(vector<int>& seg, vector<int>& arr, int ind, int l, int r) {
    if (l == r) {
        seg[ind] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(seg, arr, 2 * ind + 1, l, mid);
    build(seg, arr, 2 * ind + 2, mid + 1, r);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

// Function to query the minimum in a given range [left, right]
int query(vector<int>& seg, int index, int l, int r, int left, int right) {
    // No overlap
    if (left > r || right < l) return 0;

    // Complete overlap
    if (left <= l && r <= right) return seg[index];

    // Partial overlap
    int mid = l + (r - l) / 2;
    int ql = query(seg, 2 * index + 1, l, mid, left, right);
    int qr = query(seg, 2 * index + 2, mid + 1, r, left, right);
    return ql+qr;
}

void update(vector<int>& seg,int ind,int left,int right,int u_ind,int u_val){
    if(left == right){
        seg[ind] = u_val;
        return;
    }
    int mid = left + (right - left)/2;
    if(u_ind <=mid){
        update(seg, 2*ind+1,left, mid, u_ind, u_val);
    }else{
        update(seg, 2*ind+2,mid+1 , right, u_ind, u_val);
    }
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    // Read the array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    // Initialize the segment tree with size 4*n
    vector<int> seg(4 * n);
    
    // Build the segment tree
    build(seg, arr, 0, 0, n - 1);
    
    // Process each query
    while (q--) {
        int x;
        cin>>x;
        if(x==1){
            int k,u;
            cin>>k>>u;
            update(seg,0,0,n-1,k-1,u);
        }else{
            int l, r;
            cin >> l >> r;
            l--, r--;  // Convert to 0-based indexing
            cout << query(seg, 0, 0, n - 1, l, r) << endl;
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
