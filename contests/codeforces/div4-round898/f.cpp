/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(a) a.rbegin(), a.rend()
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solve(){
    ll n, k; cin >> n >> k;
    vll v1(n), v2(n);
    for(ll &vi: v1) cin >> vi;
    for(ll &vi: v2) cin >> vi;
    ll maximo = 0, inicio = 0, soma = 0;
    for(ll i = 0; i < n; i++){
        if(v1[i] > k){
            while(i < n && v1[i] > k) i++;
            if(i >= n) break;
            inicio = i, soma = v1[i];
        }
        else if(v2[i-1] % v2[i] != 0) inicio = i, soma = v1[i];
        else{
            soma += v1[i];
            while(soma > k) soma -= v1[inicio++];
        }
        maximo = max(maximo, i-inicio+1);
    }
    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
