#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        ll ultimo = 0, altera = 1;       
        for(ll i = 0; i < 2 * n; i++){
            if(i == ultimo + 2){
                ultimo += 2;
                altera = 1 - altera;
            }
            for(ll j = 0; j < n; j++){
                if(altera) cout << "##";
                else cout << "..";
                altera = 1 - altera;
            }
            if(n % 2 == 1) altera = 1 - altera;
            cout << '\n';
            
        }
    }
    return 0;
}
