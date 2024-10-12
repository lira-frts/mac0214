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

const ll INF = 1e18;

void solve(){
    ll k, n, x; cin >> n >> k >> x;
    vll v(n), dias;
    for(auto &vi: v) cin >> vi;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j <= n; j++)
            dias.pb(v[i] + j * x);
    sort(dias.begin(), dias.end());
    dias.erase(unique(dias.begin(), dias.end()), dias.end());
    ll ndias = dias.size();
    // pd[i][j] := insatisfação mínima dos pedidos já entregues até o dia dias[i] supondo que o último pedido entregue foi o pedido j
    vvll pd(ndias+1, vll(n+1, INF)); pd[0][0] = 0;
    ll proximo = 0;
    for(ll i = 0; i < ndias; i++){
        // acha o próximo dia se for fazer a entrega no dia dias[i]
        while(proximo < ndias && dias[proximo] < dias[i] + x) proximo++;
        for(ll j = 0; j < n; j++){
            // se não entrega mais nenhum pedido, a insatisfação é a mesma
            pd[i+1][j] = min(pd[i+1][j], pd[i][j]);
            ll atraso = pd[i][j];
            // para cada pedido não entregue ainda, supõe que vai entregar ele (e todos que vieram antes dele)
            for(ll m = j; m < min(j+k, n); m++){
                if(dias[i] < v[m]) break;
                atraso += (dias[i] - v[m]);
                // entregando somente os pedidos entre j+1 até m+1
                pd[proximo][m+1] = min(pd[proximo][m+1], atraso);
            }
        }
    }
    ll minimo = INF;
    for(ll i = 0; i <= ndias; i++) minimo = min(minimo, pd[i][n]);
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
