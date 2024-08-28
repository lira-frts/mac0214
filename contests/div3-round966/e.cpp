#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> v, mat;

ll x = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        ll w; cin >> w;
        for(ll i = 0; i < w; i++){ll x; cin >> x; v.push_back(x);}
        sort(v.begin(), v.end());
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
                mat.push_back((min(i + k - 1, n) - max(i - k, x) - (k - 1)) * (min(j + k - 1, m) - max(j - k, x) - (k - 1)));
        sort(mat.begin(), mat.end());
        ll soma = 0;
        for(ll i = w - 1; i >= 0; i--) soma += mat[n * m + i - w] * v[i];

        cout << soma << '\n';
        v.clear(); mat.clear();
    }

    return 0;
}
