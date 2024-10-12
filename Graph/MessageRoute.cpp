#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, par;

void bfs(int node, int n) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    par[node] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n) {
            return;  // Found the destination node
        }

        for (int next : adj[curr]) {
            if (!vis[next]) {
                vis[next] = 1;
                q.push(next);
                par[next] = curr;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vis.resize(n + 1, 0);
    par.resize(n + 1, -1);
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  // For undirected graph
    }

    bfs(1, n);

    // Constructing the path from node 1 to node n
    if (vis[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        int curr = n;
        while (curr != -1) {
            path.push_back(curr);
            curr = par[curr];
        }
        
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
