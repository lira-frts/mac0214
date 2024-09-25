/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pl = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpl = vector<pl>;
using vlll = vector<lll>;

void solve(){
    ll n; cin >> n;
    ll mat1[n][n], mat2[n][n], mat3[n][n], mat4[n][n];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++){
            char c; cin >> c; mat1[i][j] = (c == '1');
        }
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) mat2[i][j] = mat1[n - 1 - j][i];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) mat3[i][j] = mat2[n - 1 - j][i];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) mat4[i][j] = mat3[n - 1 - j][i];
    ll soma = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++){
            ll cont1 = mat1[i][j] + mat2[i][j] + mat3[i][j] + mat4[i][j];
            soma += min(cont1, 4 - cont1);
        }
    cout << soma / 4 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
