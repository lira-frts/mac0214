#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll h, w, q; cin >> h >> w >> q;

    set<ll> colunas_na_linha[h], linhas_na_coluna[w];

    for(ll i = 0; i < h; i++)
        for(ll j = 0; j < w; j++)
            colunas_na_linha[i].insert(j);
    
    for(ll i = 0; i < w; i++)
        for(ll j = 0; j < h; j++)
            linhas_na_coluna[i].insert(j);

    while(q--){
        ll r, c; cin >> r >> c; r--; c--;
        if(colunas_na_linha[r].find(c) != colunas_na_linha[r].end()){
            colunas_na_linha[r].erase(c);
            linhas_na_coluna[c].erase(r);
        }

        else{
            set<ll>::iterator lower, upper;
            lower = colunas_na_linha[r].lower_bound(c);
            if(lower != colunas_na_linha[r].begin()){
                ll x = *(--lower);
                colunas_na_linha[r].erase(x); linhas_na_coluna[x].erase(r);
            }
            upper = colunas_na_linha[r].upper_bound(c);
            if(upper != colunas_na_linha[r].end()){
                ll x = *(upper);
                colunas_na_linha[r].erase(x); linhas_na_coluna[x].erase(r);
            }
            lower = linhas_na_coluna[c].lower_bound(r);
            if(lower != linhas_na_coluna[c].begin()){
                ll x = *(--lower);
                linhas_na_coluna[c].erase(x); colunas_na_linha[x].erase(c);
            }
            upper = linhas_na_coluna[c].upper_bound(r);
            if(upper != linhas_na_coluna[c].end()){
                ll x = *(upper);
                linhas_na_coluna[c].erase(x); colunas_na_linha[x].erase(c);
            }
        }
    }
    
    ll soma = 0;
    for(ll i = 0; i < h; i++) soma += colunas_na_linha[i].size();

    cout << soma << '\n';

}
