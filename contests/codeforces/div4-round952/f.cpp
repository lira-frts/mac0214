#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll h, n; cin >> h >> n; 
    set<tuple<ll, ll, ll>> s;
    vector<ll> dano(n), cooldown(n);
    ll dano_inicial = 0, tempo = 1;
    for(ll i = 0; i < n; i++){
        cin >> dano[i];
        dano_inicial += dano[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> cooldown[i];
        s.insert({1 + cooldown[i], dano[i], i});
    }
    h -= dano_inicial;
    ll ultimo_tempo = 0;
    while(h > 0){
        auto[t, a, i] = *s.begin();
        if(tempo == t){
            s.erase({t, a, i});
            s.insert({tempo + cooldown[i], a, i});
            h -= a;
        }
        else tempo = t;
    }
    cout << tempo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
