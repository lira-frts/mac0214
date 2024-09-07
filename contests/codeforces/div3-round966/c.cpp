#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<ll> numeros;
vector<ll> v(200000), letras(26);
string s;

#define MAX 1234567890

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < n; i++) cin >> v[i];
        ll m; cin >> m;
        while(m--){
            for(ll i = 0; i < 26; i++) letras[i] = MAX;
            cin >> s;
            numeros.clear();
            bool flag = 1;
            if(s.size() != n) flag = 0;
            else
                for(ll i = 0; i < s.size(); i++){
                    if(letras[s[i] - 'a'] == MAX){
                        if(numeros.count(v[i])){flag = 0; break;}
                        else{letras[s[i] - 'a'] = v[i]; numeros.insert(v[i]);}
                    }
                    else if(letras[s[i] - 'a'] != v[i]){flag = 0; break;}
                }
            if(flag) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}
