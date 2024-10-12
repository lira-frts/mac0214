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

#define pb push_back
#define all(x) x.begin(),x.end()

char mat[3000][3000], aux[3000][3000];
ll n;

void rotaciona(ll x){
    for(ll i = x; i < n-x; i++){
        aux[x][i] = mat[x][i], aux[n-x-1][i] = mat[n-x-1][i];
        aux[i][x] = mat[i][x], aux[i][n-x-1] = mat[i][n-x-1];
    }
    for(ll i = x; i < n-x; i++){
        mat[x][i] = aux[n-i-1][x]; mat[i][n-x-1] = aux[x][i];
        mat[n-x-1][n-i-1] = aux[i][n-x-1]; mat[i][x] = aux[n-x-1][i];
    }
}

void solve(){
    cin >> n;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) cin >> mat[i][j];
    for(ll i = 0; i < n/2; i++)
        for(ll rot = 0; rot < (i+1)%4; rot++) rotaciona(i);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++) cout << mat[i][j]; cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
