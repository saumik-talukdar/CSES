#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n,sum=0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        long long x;
        cin>>x;
        sum+=x;
    }
    sum-=(n*(n+1)/2);
    cout<<-1*sum<<endl;

    return 0;
}
