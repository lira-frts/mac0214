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

void solve(){
    ll n, k, q; cin >> n >> k >> q;
    vvll mat(n, vll(k));
    for(ll j = 0; j < k; j++) cin >> mat[0][j];
    for(ll i = 1; i < n; i++) 
        for(ll j = 0; j < k; j++) cin >> mat[i][j], mat[i][j] |= mat[i-1][j];

    vvll mat2(k, vll(n));
    for(ll i = 0; i < k; i++)
        for(ll j = 0; j < n; j++) mat2[i][j] = mat[j][i];

    while(q--){
        ll m; cin >> m;

        ll minimo = 0, maximo = n-1;

        while(m--){
            ll r; cin >> r; r--;
            char o; cin >> o;
            ll c; cin >> c;
            if(o == '>'){
                ll x = upper_bound(mat2[r].begin(), mat2[r].end(), c) - mat2[r].begin();
                minimo = max(minimo, x);
            }
            else{
                ll x = --lower_bound(mat2[r].begin(), mat2[r].end(), c) - mat2[r].begin();
                maximo = min(maximo, x);
            }
        }
        cout << (minimo > maximo ? -1 : minimo+1) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
