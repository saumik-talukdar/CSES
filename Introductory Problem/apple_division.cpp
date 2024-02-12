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
    ll sum=0;
    cin>>n;
    int num=1<<n;
    num--;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    //cout<<sum<<endl;
    ll sum3=sum;
    
    for(int i=1;i<=num;i++){
        int j=n-1;
        ll sum2=0;
        int temp=i;
        while(temp){
            if(temp&1){
                sum2+=arr[j];
            }
            j--;
            temp=temp>>1;
        }
        //cout<<sum2<<" "<<sum3<<endl;
        ll s1=sum-sum2;
        s1=abs(s1-sum2);
        sum3=min(sum3,s1);
    }
    cout<<sum3<<endl;
    return 0;
}