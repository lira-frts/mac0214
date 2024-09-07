#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> v(n + 2), s(2 * n + 1);
    v[0] = 0;
    for(ll i = 1; i <= n; i++) cin >> v[i];
    s[0] = 0;
    for(ll i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + v[(i - 1) % n + 1];
    while(q--){
        ll l, r; cin >> l >> r;

            ll intervalo_completo;
            if((l + n - 1) / n != (r + n - 1) / n) intervalo_completo = ((r + n - 1) / n - (l + n - 1) / n) * s[n];
            else intervalo_completo = 0;

            // tira esquerda a mais
            ll qtd_deslocada = (l + n - 1) / n - 1;
            ll posicao_atual = (l - 1) % n;
            ll tira_esquerda;
            if(posicao_atual != 0){
                ll posicao_real = qtd_deslocada + posicao_atual;
                if(posicao_real > n) posicao_real %= n;
                tira_esquerda = s[n + posicao_real] - s[n + posicao_real - posicao_atual];
            }
            else tira_esquerda = 0;    

            // adiciona direita a menos
            qtd_deslocada = (r + n - 1) / n - 1;
            posicao_atual = r % n;
            ll adiciona_direita;
            if(posicao_atual != 0){
                ll posicao_real = qtd_deslocada + posicao_atual;
                if(posicao_real > n) posicao_real %= n;
                adiciona_direita = s[n + posicao_real] - s[n + posicao_real - posicao_atual];
            }
            else adiciona_direita = s[n];

            cout << intervalo_completo - tira_esquerda + adiciona_direita << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
