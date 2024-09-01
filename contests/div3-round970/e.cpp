#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n; string s;
ll max_par, max_impar;
ll cont_par[26], cont_impar[26];

void cont_letra(ll a, ll b, ll paridade_inicial){
    ll paridade_atual = paridade_inicial;
    max_par = 0, max_impar = 0;
    for(ll i = a; i <= b; i++){
        if(paridade_atual == 0) cont_par[s[i] - 'a']++;
        else cont_impar[s[i] - 'a']++;
        paridade_atual = 1 - paridade_atual;
    }
    for(ll i = 0; i < 26; i++){max_par = max(cont_par[i], max_par), max_impar = max(cont_impar[i], max_impar);}
}


void solve(){
    cin >> n; cin >> s;
    if(n % 2 == 0){
        for(ll i = 0; i < 26; i++){cont_par[i] = 0, cont_impar[i] = 0;}
        cont_letra(0, n - 1, 1);
        cout << n - max_par - max_impar << '\n';
    }
    else if(n == 1) cout << 1 << '\n';
    else{
        // melhor caso tirando uma letra de posição par
        for(ll i = 0; i < 26; i++){cont_par[i] = 0, cont_impar[i] = 0;}
        cont_letra(1, n - 1, 1);
        ll resp = n - 1 - max_par - max_impar;
        ll atual = 2;
        while(atual < n){
            max_par = 0, max_impar = 0;
            cont_impar[s[atual - 2] - 'a']++;
            cont_impar[s[atual - 1] - 'a']--;
            cont_par[s[atual - 1] - 'a']++;
            cont_par[s[atual] - 'a']--;
            for(ll i = 0; i < 26; i++){max_par = max(cont_par[i], max_par), max_impar = max(cont_impar[i], max_impar);} 
            resp = min(resp, n - 1 - max_par - max_impar);
            atual += 2;
        }
        // melhor caso tirando uma letra de posição ímpar
        for(ll i = 0; i < 26; i++){cont_par[i] = 0, cont_impar[i] = 0;}
        cont_impar[s[0] - 'a'] = 1;
        cont_letra(2, n - 1, 0);
        resp = min(resp, n - 1 - max_par - max_impar);
        atual = 3;
        while(atual < n){
            max_par = 0, max_impar = 0;
            cont_par[s[atual - 2] - 'a']++;
            cont_par[s[atual - 1] - 'a']--;
            cont_impar[s[atual - 1] - 'a']++;
            cont_impar[s[atual] - 'a']--;
            for(ll i = 0; i < 26; i++){max_par = max(cont_par[i], max_par), max_impar = max(cont_impar[i], max_impar);}
            resp = min(resp, n - 1 - max_par - max_impar);
            atual += 2;
        }

        cout << resp + 1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
