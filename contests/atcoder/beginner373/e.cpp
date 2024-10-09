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
    ll n, m, k; cin >> n >> m >> k;
    vpll v(n);
    ll soma = 0;
    for(ll i = 0; i < n; i++) cin >> v[i].first, soma += v[i].first, v[i].second = i;
    vll resp(n, 0);

    if(n == m){
        for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
        return;
    }

    sort(all(v));
    vll acc(n+1);
    acc[0] = 0;
    for(ll i = 1; i <= n; i++) acc[i] = v[i-1].first + acc[i-1];

    for(ll i = 0; i < n; i++){
        auto[val, ind] = v[i];
    
        ll inicio = val, fim = val + k - soma;
        while(inicio <= fim){

            // tá chutando que se os votos nele ficarem nessa qtd, ele ganha
            ll meio = (inicio + fim) / 2;
            ll falta = meio - val;
            bool flag = 1;

            ll pos = --lower_bound(v.begin(), v.end(), (pll) {meio+1, 0}) - v.begin();

            // é tudo mundo maior
            if(pos < n-m) flag = 0;

            // não é todo mundo maior e o cara atual tá antes
            else if(i < n-m){
                ll outros = (meio+1) * (pos - (n - m - 1)) - (acc[pos+1] - acc[n-m]);
                if(falta + outros <= k - soma) flag = 0;
            }

            // não é todo mundo maior e o cara atual tá no meio
            else{
                ll outros = (meio+1) * (pos - (n - m - 1)) - (acc[pos+1] - acc[n-m-1] - val);
                if(falta + outros <= k - soma) flag = 0;
            }

            if(flag) fim = meio - 1;
            else inicio = meio + 1;
        }
        if(inicio > val + k - soma) resp[ind] = -1;
        else resp[ind] = inicio-val;
    }
    for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
