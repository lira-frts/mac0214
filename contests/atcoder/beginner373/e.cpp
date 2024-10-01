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

            auto lower = upper_bound(v.begin(), v.end(), (pll) {meio, -1});

            // caso em que só precisa dar pros m últimos
            if(i <= n - 1 - m){
                if(--lower - v.begin() >= n-m+1){
                    ll ultimo = --lower - v.begin();
                    ll outros = m * (meio + 1) - (acc[ultimo] - acc[n-m]);
                    if(outros <= 0 || falta + outros <= k - soma) flag = 0;
                }
                else flag = 0;
            }

            // caso em que o cara atual tá no "meio"
            else{
                if(--lower - v.begin() >= n-m){
                    ll ultimo = --lower - v.begin();
                    ll outros = m * (meio + 1) - (acc[ultimo] - acc[n-m-1] - val);
                    if(outros <= 0 || falta + outros <= k - soma) flag = 0;
                }
                else flag = 0;
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
