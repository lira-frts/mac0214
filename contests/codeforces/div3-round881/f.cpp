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

struct info{
    ll sum, minPrefL, maxPrefL, minPrefR, maxPrefR, minSeg, maxSeg;
 
    info(ll el = 0) {
        sum = el;
        minSeg = minPrefL = minPrefR = min(el, 0LL);
        maxSeg = maxPrefL = maxPrefR = max(el, 0LL);
    }
};

info merge(info &a, info &b){
    info res;
    res.sum = a.sum + b.sum;
    res.minPrefL = min(a.minPrefL, a.sum + b.minPrefL);
    res.maxPrefL = max(a.maxPrefL, a.sum + b.maxPrefL);
    res.minPrefR = min(a.minPrefR + b.sum, b.minPrefR);
    res.maxPrefR = max(a.maxPrefR + b.sum, b.maxPrefR);
    res.minSeg = min({a.minSeg, b.minSeg, a.minPrefR + b.minPrefL});
    res.maxSeg = max({a.maxSeg, b.maxSeg, a.maxPrefR + b.maxPrefL});
    return res;
}

const ll MAXN = 2e5+1;
const ll lg = 17;

// up[i][j] := onde o vértice j estará após 2^i pulos
ll up[lg + 1][MAXN];

// ans[i][j] := informações no intervalo de j até j + 2^i - 1
info ans[lg + 1][MAXN];

// distância até a raiz
ll d[MAXN];
 
void solve(){
    ll n; cin >> n;

    ll ultimo_v = 0;
    for(ll i = 0; i <= lg; i++) up[i][ultimo_v] = 0;
    ans[0][ultimo_v] = info(1);
    for(ll i = 1; i <= lg; i++) ans[i][ultimo_v] = merge(ans[i-1][ultimo_v], ans[i-1][up[i-1][ultimo_v]]);
    d[ultimo_v] = 0;

    while(n--){
        char c; cin >> c;

        if(c == '+'){
            ll v, x; cin >> v >> x; v--;
            ultimo_v++;

            d[ultimo_v] = d[v] + 1;

            up[0][ultimo_v] = v;
            for(ll i = 1; i <= lg; i++) up[i][ultimo_v] = up[i-1][up[i-1][ultimo_v]];

            ans[0][ultimo_v] = info(x);
            for(ll i = 1; i <= lg; i++) ans[i][ultimo_v] = merge(ans[i-1][ultimo_v], ans[i-1][up[i-1][ultimo_v]]);
        }

        else{
            ll u, v, x; cin >> u >> v >> x; u--, v--;
            if(d[u] < d[v]) swap(u, v);
            ll dif = d[u] - d[v];

            info a, b;
           
            // faz o u ficar no mesmo nível do v, além disso, a está guardando as informações do segmento
            for(ll i = lg; i >= 0; i--)
                if((dif >> i) & 1)
                    // dá merge e pula para o próximo cara
                    a = merge(a, ans[i][u]), u = up[i][u];
 
            // no final do for, não deu merge com o último cara, então dá
            if(u == v) a = merge(a, ans[0][u]);

            else{
                for(ll i = lg; i >= 0; i--)
                    // se eles não chegam no mesmo ancestral em comum, dão o pulo
                    if(up[i][u] != up[i][v]){
                        a = merge(a, ans[i][u]), u = up[i][u];
                        b = merge(b, ans[i][v]), v = up[i][v];
                    }
                // no final, somente u dá um pulo pro ancestral em comum
                a = merge(a, ans[1][u]);
                b = merge(b, ans[0][v]);
            }
 
            swap(b.minPrefL, b.minPrefR);
            swap(b.maxPrefL, b.maxPrefR);
 
            info res = merge(a, b);

            if(res.minSeg <= x && x <= res.maxSeg) cout << "yes\n";
            else cout << "no\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
