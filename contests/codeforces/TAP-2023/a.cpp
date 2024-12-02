#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define muito std::cout.tie(NULL);
#define coxa std::cin.tie(NULL);
#define int long long

using namespace std;

using vll = vector<int>;
using pll = pair<int, int>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

void solve(){
    int n, m; cin >> n >> m;        
    vll trips(n), offices;
    int minimo = 1e18;
    for(int &i : trips) cin >> i;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(x < minimo) offices.push_back(x), minimo = x;
    }
    reverse(offices.begin(), offices.end());
    for(int i = 0; i < n; i++){
        int x = trips[i];
        int pos = offices.size()-1;
        while(pos >= 0){
            x %= offices[pos];
            pos = --upper_bound(offices.begin(), offices.end(), x) - offices.begin();
        }
        cout << x << ' ';
    }
    cout << '\n';
}

signed main(){
    MAC0214 muito coxa
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
