#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> soma_acumulada(200001);
string s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        for(ll i = 1; i <= n; i++){
            ll x; cin >> x; soma_acumulada[i] = soma_acumulada[i - 1] + x;
        }
        cin >> s;
        ll soma = 0, p1 = 0, p2 = n - 1;
        while(1){
            while(p1 < n && s[p1] != 'L') p1++;
            while(p2 >= 0 && s[p2] != 'R') p2--;
            if(p1 > p2) break;
            else{soma += soma_acumulada[p2 + 1] - soma_acumulada[p1]; p1++; p2--;}
        }
        cout << soma << '\n';
    }

    return 0;
}
