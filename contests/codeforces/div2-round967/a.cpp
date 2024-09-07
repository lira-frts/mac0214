#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> qtd(101);

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    ll t; cin >> t;

    while(t--){
        for(ll i = 0; i <= 100; i++) qtd[i] = 0;
        ll n; cin >> n;
        for(ll i = 0; i < n; i++){ll x; cin >> x; qtd[x]++;}
        ll m = -1, ind;
        for(ll i = 0; i <= 100; i++) if(qtd[i] > m){m = qtd[i], ind = i;}
        cout << n - qtd[ind] << '\n';
    }

    return 0;
}
