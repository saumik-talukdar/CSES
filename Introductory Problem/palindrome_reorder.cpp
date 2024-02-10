#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define W(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define MOD1 998244353
#define INF 1e18
#define nline "\n"

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (auto i : s)
    {
        int k = i - 'A';
        v[k]++;
    }
    int cnt = 0;
    for (auto i : v)
    {
        if (i & 1)
            cnt++;
    }
    string s1 = "";
    string s2 = "";
    if (cnt > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (v[i] & 1)
            {
                for (int j = 0; j < v[i]; j++)
                {
                    char ch = 'A' + i;
                    s2.pb(ch);
                }
            }
            else
            {
                for (int j = 0; 2 * j < v[i]; j++)
                {
                    char ch = 'A' + i;
                    s1.pb(ch);
                }
            }
        }
        string s = s1 + s2;
        reverse(s1.begin(), s1.end());
        s += s1;
        cout << s << endl;
    }

    return 0;
}