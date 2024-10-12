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

const ll INF = 1e10;

void solve(){
    ll n; cin >> n;
    vpll v(n);
    ll soma = 0;
    for(auto &[a, b]: v) cin >> a >> b, soma += b;
    if(soma % 3 != 0){
        cout << -1 << '\n';
        return;
    }
    ll s = soma/3;
    vvll pd(s+1, vll(s+1, INF)); pd[0][0] = 0;
    for(ll i = 0; i < n; i++){
        vvll pd_aux(s+1, vll(s+1, INF));
        ll b = v[i].second;
        for(ll j = 0; j <= s; j++){
            for(ll k = 0; k <= s; k++){
                if(v[i].first == 1){
                    if(j+b <= s) pd_aux[j+b][k] = min(pd_aux[j+b][k], pd[j][k]);
                    if(k+b <= s) pd_aux[j][k+b] = min(pd_aux[j][k+b], pd[j][k] + 1);
                    pd_aux[j][k] = min(pd_aux[j][k], pd[j][k] + 1);
                }
                if(v[i].first == 2){
                    if(j+b <= s) pd_aux[j+b][k] = min(pd_aux[j+b][k], pd[j][k] + 1);
                    if(k+b <= s) pd_aux[j][k+b] = min(pd_aux[j][k+b], pd[j][k]);
                    pd_aux[j][k] = min(pd_aux[j][k], pd[j][k] + 1);
                }
                if(v[i].first == 3){
                    if(j+b <= s) pd_aux[j+b][k] = min(pd_aux[j+b][k], pd[j][k] + 1);
                    if(k+b <= s) pd_aux[j][k+b] = min(pd_aux[j][k+b], pd[j][k] + 1);
                    pd_aux[j][k] = min(pd_aux[j][k], pd[j][k]);
                }

            }
        }
        for(ll j = 0; j <= s; j++)
            for(ll k = 0; k <= s; k++)
                pd[j][k] = pd_aux[j][k];
    }
    cout << (pd[s][s] == INF ? -1 : pd[s][s]) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
