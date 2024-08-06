#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        string s, t; cin >> t >> s;
        bool flag = 0;

        if(s.size() <= t.size()){
            ll ind_s = 0, ind_t = 0;
            while(ind_t < t.size()){
                if(t[ind_t] == '?') t[ind_t++] = s[ind_s++]; 
                else if(t[ind_t] == s[ind_s]){ind_t++; ind_s++;}
                else ind_t++;
                if(ind_s == s.size()){flag = 1; break;}
            }
            while(ind_t < t.size()){
                if(t[ind_t] == '?') t[ind_t] = 'a';
                ind_t++;
            }
        }

        if(flag) cout << "yes\n" << t << '\n';
        else cout << "no\n";
    }

    return 0;
}
