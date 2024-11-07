#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

struct Customer {
    int arrival, departure, idx;
};

void solve() {
    int n;
    cin >> n;
    vector<Customer> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].idx = i; // track original index
    }
    
    // Sort customers by arrival time
    sort(customers.begin(), customers.end(), [](Customer &a, Customer &b) {
        return a.arrival < b.arrival;
    });
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (departure time, room number)
    vector<int> room_assignment(n); // stores which room each customer gets
    int room_count = 0; // total rooms used

    for (int i = 0; i < n; ++i) {
        int a = customers[i].arrival;
        int b = customers[i].departure;
        int idx = customers[i].idx;
        
        // Check if any room can be freed (if departure time <= current arrival time)
        if (!pq.empty() && pq.top().first < a) {
            // reuse a room
            room_assignment[idx] = pq.top().second;
            pq.pop();
        } else {
            // no rooms are free, allocate a new room
            room_count++;
            room_assignment[idx] = room_count;
        }
        pq.push({b, room_assignment[idx]});
    }
    
    // Output
    cout << room_count << endl;
    for (int i = 0; i < n; ++i) {
        cout << room_assignment[i] << " ";
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
