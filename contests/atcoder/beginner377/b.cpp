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
    vvll mat(8, vll(8, 1));
    for(ll i = 0; i < 8; i++){
        string s; cin >> s;
        for(ll j = 0; j < 8; j++)
            if(s[j] == '#')
                for(ll k = 0; k < 8; k++) mat[i][k] = 0, mat[k][j] = 0;
    }

    ll cont = 0;
    for(ll i = 0; i < 8; i++)
        for(ll j = 0; j < 8; j++) cont += mat[i][j];

    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
