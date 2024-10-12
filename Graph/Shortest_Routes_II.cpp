#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18; // Infinity value for initialization

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // Use minimum weight if multiple edges
        dist[v][u] = min(dist[v][u], w); // Since roads are two-way
    }
    
    floydWarshall(dist, n);
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[u][v] << endl;
        }
    }
    
    return 0;
}
