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

const ll INF = 1e18;
ll n;

// retorna um vector de pares (i, j) em que i é a qtd de movimentos
// para mover h -> t e h2 -> j
vpll move(ll h, ll t, ll h2){
    vpll res;

    // caso em que a outra mão fica parada
    if(t != h2){
        // caso em que a outra mão tá no meio
        if(min(h, t) < h2 && h2 < max(h, t)) res.pb({n-abs(h-t), h2});
        // caso em que a outra mão não tá no meio
        else res.pb({abs(h-t), h2});
    }

    // casos em que vamos mexer as duas mãos

    if(h < h2){
        if(h < t && t <= h2) res.pb({n-(t-h) + (h2-t+1), t-1});
        if(t < h || h2 <= t) res.pb({(t-h+n)%n + (t-h2+n)%n+1, (t+1)%n});
    }

    if(h > h2){
        if(h2 <= t && t < h) res.pb({n-(h-t) + (t-h2+1), t+1});
        if(t <= h2 || h < t) res.pb({(h-t+n)%n + (h2-t+n)%n+1, (t-1+n)%n});
    }

    return res;
}

void solve(){
    ll q; cin >> n >> q;
    // pd[i] := qtd mínima de movimentos sendo que a outra mão vai terminar em i
    vll pd(n, INF);
    ll ph = 0, pt = 0;
    pd[1] = 0;
    for(ll i = 1; i <= q; i++){
        vll pd2(n, INF);
        char ch; cin >> ch;
        ll h = (ch == 'R');
        ll t; cin >> t; t--;
        // escolhendo onde a outra mão tá
        for(ll j = 0; j < n; j++){
            vll pos(2);
            pos[ph] = pt; pos[1-ph] = j;
            for(auto [mov, pos]: move(pos[h], t, pos[1-h])) pd2[pos] = min(pd2[pos], pd[j] + mov);
        }    
        pd = pd2;
        ph = h, pt = t;
    }
    ll minimo = INF;
    for(ll x: pd) minimo = min(minimo, x);
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
