#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s; cin >> s; ll n = s.size();
    
    vector<vector<ll>> v(n, vector<ll>(2));

    // v[i][0] = melhor caso em que ele adiciona até chegar o valor do i-ésimo dígito
    v[0][0] = s[0] - '0';

    // v[i][1] = melhor caso em que ele remove até chegar o valor do i-ésimo dígito    
    v[0][1] = 1 + 10 - (s[0] - '0');

    for(ll i = 1; i < n; i++){

        // pega o mínimo de operações até o (i - 1)-ésimo dígito
        ll melhor_anterior = min(v[i - 1][0], v[i - 1][1]);

        // pro cara que só adiciona, basta somar o valor do dígito atual
        v[i][0] = melhor_anterior + (s[i] - '0');

        // pro cara que só remove, ele pode:

        // 1- ou começar adicionando no anterior e começar a remover a partir dele
        ll novo = v[i - 1][0] + 1 + 10 - (s[i] - '0');
        
        // 2- ou só continuar a remover do primeiro cara que já estava removendo
        ll mantem = v[i - 1][1] + 10 - (s[i] - '0') - 1;

        // ai pega o mínimo
        v[i][1] = min(novo, mantem);
    }
    
    cout << min(v[n - 1][0], v[n - 1][1]) << '\n';
}
