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
    ll n, m, k; cin >> n >> m >> k;
    vpll v(n);
    ll soma = 0;
    for(ll i = 0; i < n; i++){
        cin >> v[i].first;
        soma += v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vll resp(n, 0);

    for(ll i = 0; i < n; i++){
        auto[val, ind] = v[i];
        ll falta;
        // vai passar
        if(i < n-m){
            cout << val << ' ' << ind << endl;
            ll qtd_passa = v[n-m].first;
            if(qtd_passa - val + 1 > k - soma) resp[ind] = -1;
            else resp[ind] = (qtd_passa - val + 1) + (k - soma - (qtd_passa - val + 1)) / 2;
        }
        // só tem que ficar acima do último que não tá ganhando
        else{
            ll qtd_passa = v[n-m-1].first;
            resp[ind] = (val + k - soma - qtd_passa) / 2;
        }
    }

    for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
