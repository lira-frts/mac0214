#include <bits/stdc++.h>
using namespace std;

using ll = long long;

multiset<ll> ms;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    for(ll i = 0; i < n; i++){ll a; cin >> a; ms.insert(a);}

    ll resp = 0, soma = 0;
    ll minimo = *ms.begin(); ms.erase(ms.find(minimo));
    ll maximo;
    for(ll i = 2; i <= n; i++){ 
        if(i % 2 == 0){
            maximo = *ms.rbegin(); ms.erase(ms.find(maximo));
            soma += (maximo - minimo);
        }
        else{
            minimo = *ms.begin(); ms.erase(ms.find(minimo));
        }
        resp += soma;
        cout << resp << ' ';
    }
    cout << '\n';
}
