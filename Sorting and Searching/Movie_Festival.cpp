#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    
    // Input movie start and end times
    for(int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }
    
    // Sort movies by their end time (second in the pair)
    sort(movies.begin(), movies.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    });
    
    int count = 0;
    int last_end_time = 0;
    
    // Iterate over the movies and use the greedy strategy
    for(auto& movie : movies){
        if(movie.first >= last_end_time){
            count++;
            last_end_time = movie.second; // Update the last watched movie's end time
        }
    }
    
    // Output the maximum number of movies that can be watched
    cout << count << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
