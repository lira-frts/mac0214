#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(k);

    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;

    ll mdc = b[0];
    for(ll i = 1; i < k; i++) mdc = gcd(mdc, b[i]);

    bool flag = 1;
    ll resto = a[0] % mdc;
    for(ll i = 1; i < n; i++)
        if(a[i] % mdc != resto) flag = 0;

    cout << (flag ? "Yes\n" : "No\n");
}
