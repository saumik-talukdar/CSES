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

    int n;
    cin >> n;
    vector<string> v;
    string s1 = "";
    for (int i = 0; i < n - 2; i++)
    {
        s1.pb('0');
    }
    int num = pow(2, n);
    num--;
    v.pb(s1 + "00");
    v.pb(s1 + "01");
    v.pb(s1 + "11");
    v.pb(s1 + "10");
    if (n == 1)
    {
        cout << 0 << endl;
        cout << 1 << endl;
    }
    else
    {
        int j = 3;
        int k = n - 3;
        for (int i = 4; i <= num; i++)
        {
            string s;
            if (j < 0)
            {
                j = v.size() - 1;
                k--;
            }
            s = v[j];
            s[k] = '1';
            j--;
            v.pb(s);
            // cout<<s<<" "<<v[j+1]<<" "<<j<<" "<<k<<endl;
        }
        for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
    }

    return 0;
}