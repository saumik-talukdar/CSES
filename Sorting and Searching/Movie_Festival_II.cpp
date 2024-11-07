#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    
    // Read all movies
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a};  // Store as {end, start} to sort by end time
    }
    
    // Sort movies by end time
    sort(movies.begin(), movies.end());
    
    // Multiset to track the end times of movies currently being watched
    multiset<int> endTimes;
    int count = 0;
    
    // Go through each movie
    for(auto [end, start] : movies) {
        // Find if there is a club member whose last movie ends before the current movie starts
        auto it = endTimes.upper_bound(start);
        
        if (it != endTimes.begin()) {
            --it;
            endTimes.erase(it);  // Remove the member's last end time
            endTimes.insert(end);  // Add the new movie's end time
            count++;
        }
        else if (endTimes.size() < k) {
            endTimes.insert(end);  // Add this movie's end time to the schedule
            count++;
        }
    }
    
    cout << count << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
