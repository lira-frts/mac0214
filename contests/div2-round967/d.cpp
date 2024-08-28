#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = ll(3e5 + 1);

vector<ll> v, resp;
vector<bool> aux(N);
set<pair<ll, ll>> numeros_positivos, numeros_negativos;
stack<ll> posicoes_finais;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < n; i++){ll a; cin >> a; v.push_back(a);}
        aux.assign(n + 1, 0);
        for(ll i = n - 1; i >= 0; i--)
            if(aux[v[i]] == 0){
                posicoes_finais.push(i);
                aux[v[i]] = 1;
            }
        aux.assign(n + 1, 0);
        ll posicao = 0, impar = 1, atual, posicao_atual, posicao_valida = -1; 
        while(!posicoes_finais.empty()){
            ll proxima_posicao = posicoes_finais.top(); posicoes_finais.pop();
            if(aux[v[proxima_posicao]] == 1) continue;
            for(; posicao <= proxima_posicao; posicao++){
                numeros_positivos.insert({v[posicao], posicao});
                numeros_negativos.insert({-v[posicao], posicao});
            }
            while(aux[v[proxima_posicao]] != 1){
                if(impar){
                    atual = numeros_negativos.begin()->first;
                    posicao_atual = numeros_negativos.begin()->second;
                    numeros_negativos.erase({atual, posicao_atual});
                    atual *= -1;
                }
                else{
                    atual = numeros_positivos.begin()->first;
                    posicao_atual = numeros_positivos.begin()->second;
                    numeros_positivos.erase({atual, posicao_atual});
                }
                if(posicao_atual < posicao_valida) continue;
                if(aux[atual] == 1) continue;
                posicao_valida = posicao_atual;
                resp.push_back(atual);
                impar = 1 - impar;
                aux[atual] = 1;
            }
        }
        cout << resp.size() << '\n';
        for(ll i = 0; i < resp.size(); i++) cout << resp[i] << ' ';
        cout << '\n';
        numeros_positivos.clear(); numeros_negativos.clear(); v.clear(); resp.clear(); 
    }

    return 0;
}
