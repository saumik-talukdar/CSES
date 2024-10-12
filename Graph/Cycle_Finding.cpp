#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e18;
vector<vector<pair<int, int>>> adj;
int n, m;

bool spfa(int s, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n) {
                        // Negative cycle detected
                        int x = to;
                        for (int i = 0; i < n; i++) {
                            x = p[x];
                        }
                        vector<int> cycle;
                        for (int v = x;; v = p[v]) {
                            cycle.push_back(v);
                            if (v == x && cycle.size() > 1)
                                break;
                        }
                        reverse(cycle.begin(), cycle.end());

                        cout << "YES" << endl;
                        for (int v : cycle) {
                            cout << v << " ";
                        }
                        cout << "\n";
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    vector<int> d, p;
    bool no_negative_cycle = true;
    for (int i = 1; i <= n; i++) {
        if (spfa(i, d, p) == false) {
            no_negative_cycle = false;
            break;
        }
    }

    if (no_negative_cycle) {
        cout << "NO" << endl;
    }

    return 0;
}
