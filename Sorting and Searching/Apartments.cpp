#include<bits/stdc++.h>
using namespace std;

#define int long long
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl

#define all(v) v.begin(),v.end()

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> desired(n);
    vector<int> apartment(m);

    for(int i = 0; i < n; i++) cin >> desired[i];
    for(int i = 0; i < m; i++) cin >> apartment[i];
    
    // Sort both arrays
    sort(all(desired));
    sort(all(apartment));

    int i = 0, j = 0, count = 0;

    // Two-pointer approach to match applicants with apartments
    while (i < n && j < m) {
        if (apartment[j] >= desired[i] - k && apartment[j] <= desired[i] + k) {
            // Match found
            count++;
            i++;
            j++;
        }
        else if (apartment[j] < desired[i] - k) {
            // Apartment is too small, move to the next apartment
            j++;
        }
        else {
            // Desired apartment is too small, move to the next applicant
            i++;
        }
    }

    cout << count << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
