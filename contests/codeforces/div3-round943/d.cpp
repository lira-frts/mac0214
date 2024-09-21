/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NMAX = 2e5+1;

vector<ll> a(NMAX), p(NMAX);
ll n, k;

ll pontos(ll inicio){
    vector<ll> dist(n+1, -1);
    ll atual = inicio, maximo = a[inicio], indice = inicio;
    for(ll d = 0; d < k; d++){
        if(dist[atual] != -1) break;
        dist[atual] = d;
        if(a[atual] > maximo) maximo = a[atual], indice = atual;
        atual = p[atual];
    }
    ll pontos = 0, acc = 0;
    atual = inicio;
    for(ll d = 0; d <= dist[indice]; d++){
        pontos = max(pontos, acc + (k - d) * a[atual]);
        acc += a[atual];
        atual = p[atual];
    }
    return pontos;
}

void solve(){
    ll pb, ps; cin >> n >> k >> pb >> ps;
    for(ll i = 1; i <= n; i++) cin >> p[i];
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll pontosb = pontos(pb), pontoss = pontos(ps);
    if(pontosb > pontoss) cout << "Bodya\n";
    else if(pontoss > pontosb) cout << "Sasha\n";
    else cout << "Draw\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
