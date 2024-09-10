#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <const int MOD>
struct mint {
	ll x;
	mint(): x(0) {}
	mint(ll _x): x(_x%MOD<0?_x%MOD+MOD:_x%MOD) {}
	void operator+=(mint rhs) { x+=rhs.x; if(x>=MOD) x-=MOD; }
	void operator-=(mint rhs) { x-=rhs.x; if(x<0)x+=MOD; }
	void operator*=(mint rhs) { x*=rhs.x; x%=MOD; }
	void operator/=(mint rhs) { *this *= rhs.inv(); }
	mint operator+(mint rhs) { mint res=*this; res+=rhs; return res; }
	mint operator-(mint rhs) { mint res=*this; res-=rhs; return res; }
	mint operator*(mint rhs) { mint res=*this; res*=rhs; return res; }
	mint operator/(mint rhs) { mint res=*this; res/=rhs; return res; }
	mint inv() { return this->pow(MOD-2); }
	mint pow(ll e) {
		mint res(1);
		for(mint p=*this;e>0;e/=2,p*=p) if(e%2)
			res*=p;
		return res;
	}
};

using Z = mint<1000000007>;
Z fat[200001];

Z escolhe(ll n, ll k){
    if(k > n) return 0;
    return fat[n] / (fat[n - k] * fat[k]);
}

void solve(){
    string s; cin >> s;
    ll cont0 = 0, cont1 = 0;
    Z resp = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '0') cont0++;
        else cont1++;
    }
    for(ll i = 1; i <= min(cont0, cont1); i++) resp += escolhe(cont0, i) * escolhe(cont1, i);
    cout << resp.x << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Z aux = 0;
    fat[0] = 1;
    for(ll i = 1; i <= 2e5; i++) aux = aux + 1, fat[i] = aux * fat[i - 1];

    ll t; cin >> t;
    while(t--) solve();
}
