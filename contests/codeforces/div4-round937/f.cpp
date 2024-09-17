/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll a, b, c; cin >> a >> b >> c;
    if(a + 1 != c){
        cout << -1 << '\n';
        return;
    }
    if(a == 0){
        cout << b << '\n';
        return;
    }

    // h inicialmente é altura pra completar de 2
    ll h = log2(a+1) - 1;

    ll filhos = pow(2, h+1);
    ll resto = a - (pow(2, h+1) - 1);

    if(resto != 0){
        b = max(b - (filhos - resto), 0LL);
        // completou a altura de 2 incompleta
        h += 1;
        filhos += resto;
    }

    // completa com de 1 e de 0
    h += (b + filhos - 1) / filhos + 1;
    cout << h << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
