#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.length();

    
    int ct = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        c++;
        if (s[i] != s[i + 1])
        {
            if (c > ct)
            {
                ct = c;
                c = 0;
            }
            else
            {
                c = 0;
            }
        }
    }

    cout << ct << endl;
    return 0;
}
