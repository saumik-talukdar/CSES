#include<bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define W(t) int t;cin >> t;while(t--)
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
string permutation;
set<string> s1;
bool chosen[8]={false};
int n;
string s;
void search()
{
    if (permutation.size() == n)
    {
        // process permutation
        s1.insert(permutation);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(s[i]);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    cin>>s;
    n=s.size();;
    search();
    cout<<s1.size()<<endl;
    for(auto i : s1){
        cout<<i<<endl;
    }
    return 0;
}