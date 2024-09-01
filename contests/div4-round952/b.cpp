#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    ll maximo = -1, resp;
    for(ll i = 2; i <= n; i++){
        ll soma = 0;
        for(ll k = 1; i * k <= n; k++) soma += i * k;
        if(soma > maximo){maximo = soma, resp = i;}
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
