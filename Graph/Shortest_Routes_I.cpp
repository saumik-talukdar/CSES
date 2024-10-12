#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=1e18+9;

vector<vector<pair<int,int>> > adj(1000006);
int vis[1000006];
vector<int> dist(1000006,inf);

void dijkstra(int node) {
    dist[node] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[node], node});
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        int cdist = pq.top().first;
        pq.pop();
        /*
        It's important to include continue. This ensures that when all edge weights
are non-negative, we will never go through the adjacency list of any vertex more
than once. Removing it will cause TLE on the last test case of the above
problem!
The last test case contains 100000 destinations and 149997 flights. City 1 has
flights to cities 2 through 50000. Cities 2 through 50000 have flights to
city 50001. City 50001 has flights to cities 50002 through 100000. Without the
continue, after the program pops cities 1 through 50000 off the queue, the
priority queue will contain 49999 routes that end at city 50001. Every one of
the 49999 times city 50001 is popped off the queue and processed, we must
iterate over all of its outgoing flights (to cities 50002 through 100000). This
results in a runtime of $\Theta(N^2\log N)$, which will TLE.
On the other hand, if we did include the continue, the program will never
iterate through the adjacency list of city 50001 after processing it for the
first time.
        */
        if (cdist != dist[curr]) { continue; }
        for (const pair<int,int>& child : adj[curr]) {
            if (dist[curr] + child.second < dist[child.first]) {
                dist[child.first] = dist[curr] + child.second;
                pq.push({dist[child.first], child.first});
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    dijkstra(1);

    for(int i=1 ; i<=n; i++)cout<<dist[i]<<" ";
    return 0;
}

