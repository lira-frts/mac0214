#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 10000000;

// primeiro divisor primo
vector<ll> lp(N+1);

// primos
vector<ll> pr;

// acha os números primos e o primeiro divisor primo
void linear_sieve(){
    for(ll i = 2; i <= N; ++i){
        // achou um novo primo
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        // linear (lp[i * pr[j]] é setado uma única vez)
        for(ll j = 0; i * pr[j] <= N; ++j){
            // marca para os múltiplos do número atual quem é o menor primo divisor
            // (só acha múltiplos k em que lp[k] <= lp[i])
            lp[i * pr[j]] = pr[j];
            // termina se chegou no primeiro primo que divide o número atual
            if(pr[j] == lp[i]) break;
        }
    }
}

vector<ll> mex(N+1);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    linear_sieve();

    ll ind = 1; mex[1] = 1; mex[3] = 2;
    for(ll i = 4; i <= N; ++i){
        if(lp[i] == i) mex[i] = mex[pr[ind++]] + 1;
        else mex[i] = mex[lp[i]];
    }
    
    while(t--){
        ll n; cin >> n;
        ll XOR = 0;

        while(n--){
            ll a; cin >> a;
            XOR = XOR ^ mex[a];
        }
        
        cout << (XOR ? "Alice\n" : "Bob\n");
    }

    return 0;
}
