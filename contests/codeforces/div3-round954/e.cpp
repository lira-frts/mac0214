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
#define rall(a) a.rbegin(), a.rend()
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solve(){
    ll n, k; cin >> n >> k;
    map<ll, vll> mp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x; mp[x%k].pb(x);
    }
    ll qtd_impar = 0;
    for(auto &[key, value]: mp) qtd_impar += value.size() % 2;
    if(qtd_impar >= 2){
        cout << "-1 \n";
        return;
    }
    ll soma = 0;
    for(auto &[key, value]: mp){
        sort(all(value));
        if(value.size() % 2 == 1){
            ll minimo = 0;
            for(ll i = 2; i < value.size(); i += 2) minimo += (value[i] - value[i-1]) / k;
            ll aux = minimo;
            for(ll i = 1; i < value.size(); i++){
                ll sinal = (i % 2) ? 1 : -1;
                aux += (sinal * value[i] + (-sinal) * value[i-1]) / k;
                minimo = min(minimo, aux); 
            }
            soma += minimo;
        }
        else for(ll i = 1; i < value.size(); i += 2) soma += (value[i] - value[i-1]) / k;
    }
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
