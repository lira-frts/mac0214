/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpll = vector<pll>;
using vlll = vector<lll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

const ll INF = 1e18;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    vpll v(n+1);
    for(ll i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    // último dia fictício para rodar o último dia de vdd que a gente adicionou no final
    v[n] = {INF, 0};

    stack<pll> stack;
    ll dia_atual = 1, leite_bebido = 0, cont = 0;

    for(ll i = 0; i <= n; i++){
        // pega o do dia atual
        auto [dia, qtd] = v[i];

        // ou bebe tudo que tem ou bebe até o dia anterior ao dia de hj
        while(!stack.empty() && dia_atual < dia){

            // leite mais fresco
            auto [d, x] = stack.top(); stack.pop();

            // se já venceu, vai pro próximo
            if(d + k - 1 < dia_atual) continue;

            // caso em que terminou de beber tudo antes do leite da última iteração
            if(d > dia_atual) dia_atual = d, leite_bebido = 0;

            // caso em que o leite não é suficiente
            if(m - leite_bebido > x) leite_bebido += x;

            // caso em que dá pra beber leite por alguns dias
            else{
                // ou bebe tudo que tem, ou até estragar, ou até o dia anterior ao dia de hj
                ll dia_final = min({dia_atual + x/m, d+k, dia});
                cont += dia_final - dia_atual;
                ll sobra = x - ((dia_final - dia_atual) * m - leite_bebido);
                if(sobra > 0) stack.push({d, sobra});
                leite_bebido = 0, dia_atual = dia_final;
            }
        }

        // adiciona o do dia atual
        stack.push({dia, qtd});
    }
    
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
