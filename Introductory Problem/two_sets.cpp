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
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    if(!(n&1)){
        int x=n/2;
        if(x&1){
            cout<<"NO"<<endl;
        }else{
            cout << "YES" << endl;
            cout<<x<<endl;
            for(int i=1;i<=n;i+=4){
                cout<<i<<" "<<i+3<<" ";
            }
            cout<<endl;
            cout<<x<<endl;
            for (int i = 2; i <= n; i += 4)
            {
                cout << i << " " << i + 1 << " ";
            }
            cout<<endl;
        }
    }else{
        int x=n/2;
        if(!(x&1)){
            cout << "NO" << endl;
        }else{
            cout<<"YES"<<endl;
            cout<<x+1<<endl;
            for(int i=1;i<n;i+=4){
                cout<<i<<" "<<i+1<<" ";
            }
            cout<<endl;
            cout<<x<<endl;
            for (int i = 3; i < n; i += 4)
            {
                cout << i << " " << i + 1 << " ";
            }
            cout<<n<<endl;
            //cout<<endl;
        }

    }
    return 0;
}