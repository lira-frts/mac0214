#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll soma_digito(ll x){
    ll soma = 0;
    while(x){soma += x % 10; x /= 10;}
    return soma;
}

void solve(){
    ll l, r, k; cin >> l >> r >> k;
    if(k >= 10) cout << 0 << '\n';
    else{
        ll qtd = 0;
        for(ll i = 0; i * k < 10; i++) qtd++;
        cout << pow(qtd, r - l) - 1<< endl;

    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
