#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll mat[101][101];
    ll n; cin >> n;

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= i; j++)
            cin >> mat[i][j];

    ll atual = 1;
    for(ll i = 1; i <= n; i++) atual = mat[max(atual, i)][min(atual, i)];
    cout << atual << '\n';

}
