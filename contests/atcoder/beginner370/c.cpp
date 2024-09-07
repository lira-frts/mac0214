#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t; cin >> s >> t;

    ll dif = 0;
    for(ll i = 0; i < s.size(); i++)
        if(s[i] != t[i]) dif++;

    cout << dif << '\n';
    string minimo;
    while(dif--){
        minimo = s;
        for(ll i = 0; i < s.size(); i++)
            if(s[i] != t[i]){minimo[i] = t[i]; break;}
        for(ll i = 0; i < s.size(); i++)
            if(s[i] != t[i]){
                string aux = s; aux[i] = t[i];
                if(aux < minimo) minimo = aux;
            }
        s = minimo;
        cout << s << '\n';
    }
}
