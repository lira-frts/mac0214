/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()

const vll dx = {0, 2, 1, -1, -2, -2, -1, 1, 2};
const vll dy = {0, 1, 2, 2, 1, -1, -2, -2, -1};

void solve(){
    ll n, m; cin >> n >> m;
    set<pll> st;
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        for(ll j = 0; j < 9; j++){
            ll a2 = a + dx[j], b2 = b + dy[j];
            if(a2 < 1 || a2 > n || b2 < 1 || b2 > n) continue;
            st.insert({a2, b2});
        }
    }
    cout << n*n - st.size() << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
