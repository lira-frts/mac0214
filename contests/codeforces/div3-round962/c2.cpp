#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAXN = 2e5+1;

ll letras_a[MAXN][26], letras_b[MAXN][26];

void solve(){
    ll n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    for(ll i = 0; i < 26; i++) letras_a[0][i] = 0, letras_b[0][i] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < 26; j++)
            letras_a[i][j] = letras_a[i-1][j], letras_b[i][j] = letras_b[i-1][j];        
        letras_a[i][a[i-1] - 'a']++, letras_b[i][b[i-1] - 'a']++;
    }

    while(q--){
        ll l, r; cin >> l >> r;
        ll dif = 0;
        for(ll i = 0; i < 26; i++) dif += abs((letras_a[r][i] - letras_a[l - 1][i]) - (letras_b[r][i] - letras_b[l - 1][i]));
        cout << dif / 2 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
