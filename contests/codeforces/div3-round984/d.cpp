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
    ll n, m; cin >> n >> m;
    char mat[n][m];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) cin >> mat[i][j];
    ll cont = 0;
    for(ll i = 0; i < min(n, m)/2; i++){
        vector<char> v;
        for(ll j = i; j < m-i; j++) v.pb(mat[i][j]);
        for(ll j = i+1; j < n-i; j++) v.pb(mat[j][m-1-i]);
        for(ll j = m-1-i-1; j >= i; j--) v.pb(mat[n-1-i][j]);
        for(ll j = n-1-i-1; j > i; j--) v.pb(mat[j][i]);
        for(ll j = 0; j < 3; j++) v.pb(v[j]);
        for(ll j = 0; j < v.size()-3; j++)
            if(v[j] == '1' && v[j+1] == '5' && v[j+2] == '4' && v[j+3] == '3') cont++;
    }
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
