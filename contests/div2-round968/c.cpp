#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll letras[26];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; string s; cin >> n; 
        for(ll i = 0; i < 26; i++) letras[i] = 0;
        for(ll i = 0; i < n; i++){char c; cin >> c; s.push_back(c); letras[c - 'a']++;}
        string resp; resp.push_back(s[0]); letras[s[0] - 'a']--;
        for(ll i = 1; i < n; i++){
            bool flag = 0;
            for(ll j = 0; j < 26; j++)
                if(letras[j] > 0 && resp[i - 1] - 'a' != j){resp.push_back('a' + j); letras[j]--; flag = 1; break;}
            if(flag == 0){
                for(ll j = 0; j < 26; j++)
                    if(letras[j] > 0)
                        for(ll k = letras[j]; k >= 0; k--) resp.push_back('a' + j);
                break;
            }
        }
        cout << resp << '\n';
    }

    return 0;
}
