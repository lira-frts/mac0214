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

const ll N = 10000000;

// primeiro divisor primo
vector<ll> lp(N+1);

// primos
vector<ll> pr;

// acha os números primos e o primeiro divisor primo
void linear_sieve(){
    for(ll i = 2; i <= N; ++i){
        // achou um novo primo
        if(lp[i] == 0){
            lp[i] = i;
            pr.pb(i);
        }
        // linear (lp[i * pr[j]] é setado uma única vez)
        for(ll j = 0; i * pr[j] <= N; ++j){
            // marca para os múltiplos do número atual quem é o menor primo divisor
            // (só acha múltiplos k em que lp[k] <= lp[i])
            lp[i * pr[j]] = pr[j];
            // termina se chegou no primeiro primo que divide o número atual
            if(pr[j] == lp[i]) break;
        }
    }
}

void solve(){
    ll l, r; cin >> l >> r;
    if(l == 1) l++;
    while(l <= r){
        if(lp[l] != l){
            cout << l/lp[l] << ' ' << l-l/lp[l] << '\n';
            return;
        }
        l++;
    }
    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    linear_sieve();
    while(t--) solve();
}
