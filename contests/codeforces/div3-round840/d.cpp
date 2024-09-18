/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, m; cin >> n >> m;
    ll div2 = 0, div5 = 0;


    // fatora n pra achar div2 e div5 tq. n = aux * 2 ^ div2 * 5 ^ div5
    ll aux = n;
    while(aux % 2 == 0) aux /= 2, div2++;
    while(aux % 5 == 0) aux /= 5, div5++;

    // tenta pegar fatores de uma potência de 2 ou 5 de um número <= m pra compensar o menor expoente
    ll k = 1;
    while(div2 < div5 && k * 2 <= m) div2++, k *= 2;
    while(div5 < div2 && k * 5 <= m) div5++, k *= 5;

    // se achou, tenta aumentar a qtd de zeros
    if(div2 == div5)
        while(k * 10 <= m) k *= 10;
    // depois tenta aumentar o número antes dos zeros
    if(k * 10 > m)  k *= m/k;

    cout << n * k << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
