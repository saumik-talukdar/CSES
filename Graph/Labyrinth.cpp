#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<char> dirSymbols = {'R', 'D', 'L', 'U'};
vector<vector<char>> dirNames(1001,vector<char> (1001));
vector<vector<pair<int,int>>> par(1001,vector<pair<int,int>> (1001));

bool isValid(int x, int y, int n, int m, vector<vector<char>>& labyrinth, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}
void triming(string& s){
    while(s.back()==' '){
        s.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> m;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];

            par[i][j] ={-1,-1}; 
            dirNames[i][j] =' ';

            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push({start.first, start.second});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.x == end.first && current.y == end.second) {
            cout << "YES" << endl;
            string s="";
            int currx=end.first;
            int curry=end.second;
    
            while(currx!=-1 && curry!=-1){
                s+=dirNames[currx][curry];
                pair<int,int> curr=par[currx][curry];
                currx=curr.first;
                curry=curr.second;
            }
            triming(s);
            reverse(s.begin(), s.end());
            triming(s);
            cout<<s.size()<<endl;
            cout<<s<<endl;
            return 0;
        }

        for (int i = 0; i < (int)directions.size(); i++) {
            int newX = current.x + directions[i].first;
            int newY = current.y + directions[i].second;
            if (isValid(newX, newY, n, m, labyrinth, visited)) {
                par[newX][newY] ={current.x, current.y};
                dirNames[newX][newY] = dirSymbols[i];
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
