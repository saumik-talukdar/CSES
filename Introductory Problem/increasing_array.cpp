#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n, ct = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            ct += a[i - 1] - a[i];
            a[i] += a[i - 1] - a[i];
        }
    }

    cout << ct << endl;

    return 0;
}
