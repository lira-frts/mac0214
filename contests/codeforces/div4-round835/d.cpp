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

#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){
    ll n; cin >> n;
    vll v(n);
    for(auto &x: v) cin >> x;
    vll aux;
    for(ll i = 1; i < n; i++)
        if(v[i] - v[i-1] > 0) aux.pb(1);
        else if(v[i] - v[i-1] < 0) aux.pb(-1);
    ll atual = 0;
    while(atual < aux.size() && aux[atual] == -1) atual++;
    while(atual < aux.size() && aux[atual] == 1) atual++;
    cout << (atual == aux.size() ? "yes\n" : "no\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
