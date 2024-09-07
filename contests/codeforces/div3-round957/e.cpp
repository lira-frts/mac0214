#include <bits/stdc++.h>

#define MAC214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

int numDigitos(int n){
    int cont = 0;
    while(n != 0){
        n /= 10;
        cont++;
    }
    return cont;
}

// multiplica a string n até ter tamanho igual a tamanhoFinal
int calculaString(int n, int tamanhoN, int tamanhoFinal){
    string stringN = to_string(n), final;
    for(int i = 0; i < tamanhoFinal; i++) final.push_back(stringN[i % tamanhoN]);
    return stoll(final);
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> solucoes;
    
    for(int a = 1; a <= 10000; a++){
        int lenProd = numDigitos(a * n);
        int lenN = numDigitos(n);
        int lenString = a * lenN;

        // variável pra verificar o valor de b pq não consegui colocar o próprio valor no max :(
        int x = 10000;

        // "chuta" o tamanho final e verifica se dá certo (tamanhoFinal = lenString - b)
        for(int tamanhoFinal = 1; tamanhoFinal <= lenProd; tamanhoFinal++){
            
            // condições do valor que b pode assumir
            if(lenString - tamanhoFinal < 1 || lenString - tamanhoFinal > min(x, a * n)) continue;
            
            if((a * n) - (lenString - tamanhoFinal) == calculaString(n, lenN, tamanhoFinal)) solucoes.push_back({a, lenString - tamanhoFinal});
        }
    }

    cout << solucoes.size() << '\n';
    for(auto i : solucoes) cout << i.first << ' ' << i.second << '\n';
}

signed main(){
    MAC214 coxa
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
