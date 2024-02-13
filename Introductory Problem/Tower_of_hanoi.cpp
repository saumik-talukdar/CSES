#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int, int>> v;
void tower_of_hanoi(int n, int src, int aux, int dest)
{
    if (n == 0)
        return;

    tower_of_hanoi(n - 1, src, dest, aux);
    // cout<<src<<" "<<dest<<endl;
    v.push_back({src, dest});
    tower_of_hanoi(n - 1, aux, src, dest);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int src = 1, dest = 3, aux = 2;
    tower_of_hanoi(n, src, aux, dest);
    cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
