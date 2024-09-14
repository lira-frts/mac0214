#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, m, q; cin >> n >> m >> q;
    set<ll> s; 
    for(ll i = 0; i < m; i++){ll a; cin >> a; s.insert(a);}
    while(q--){
        ll pos; cin >> pos;
        bool inicio = 0, fim = 0;
        ll anterior, proximo;
        auto lower = s.lower_bound(pos);
        if(lower != s.begin()){anterior = *(--lower); inicio = 1;}
        auto upper = s.upper_bound(pos);
        if(upper != s.end()){proximo = *upper; fim = 1;}
        if(inicio && fim) cout << (proximo - anterior) / 2 << '\n';
        else if(inicio == 0) cout << proximo - 1 << '\n';
        else cout << n - anterior << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
