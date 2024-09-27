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

void solve(){
    ll n, m; cin >> n >> m;
    vpll s(m);
    for(auto &x: s) cin >> x.first >> x.second, x.first--, x.second--;
    ll q; cin >> q;
    vll qs(q);
    for(ll &x: qs) cin >> x, x--;
    ll inicio = 0, fim = q;
    vll v(n), acc(n);
    while(inicio <= fim){
        ll meio = (inicio + fim) / 2;

        // zera tudo
        for(ll i = 0; i < n; i++) v[i] = 0, acc[i] = 0;

        // adiciona os uns
        for(ll i = 0; i < meio; i++) v[qs[i]] = 1;

        // calcula os acumulados
        if(v[0] == 0) acc[0] = 1;
        for(ll i = 1; i < n; i++){
            acc[i] = acc[i-1];
            if(v[i] == 0) acc[i] += 1;
        }
   
        bool flag = 0;

        // verifica se tem alguém que satisfaz
        for(ll i = 0; i < m; i++){
            ll l = s[i].first, r = s[i].second;
            ll zeros = acc[r];
            if(l > 0) zeros -= acc[l-1];
            if(zeros < r-l+1 - zeros) flag = 1;
        }
        if(flag) fim = meio - 1;
        else inicio = meio + 1;
    }
    cout << (fim == q ? -1 : inicio) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
