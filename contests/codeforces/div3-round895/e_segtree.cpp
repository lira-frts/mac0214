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

const ll MAXN = 1e5;

struct node{ll xor0, xor1, lazy;} t[4 * MAXN];
vll v(MAXN);
string s;

node merge(node l, node r){
    node x = {l.xor0 ^ r.xor0, l.xor1 ^ r.xor1, 0};
    return x;
}

void build(ll p, ll l, ll r){
    if(l == r){
        if(s[l] == '0') t[p] = {v[l], 0, 0};
        else t[p] = {0, v[l], 0};
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

void unlazy(ll p, ll l, ll r){
    if(t[p].lazy == 0) return;
    if(t[p].lazy % 2 == 1) swap(t[p].xor0, t[p].xor1);
    if(l != r){
        t[2 * p].lazy += t[p].lazy;
        t[2 * p + 1].lazy += t[p].lazy;
    }
    t[p].lazy = 0;
}

void update(ll p, ll l, ll r, ll ul, ll ur){
    unlazy(p, l, r);
    if(l > ur || r < ul) return;
    if(l >= ul && r <= ur){
        t[p].lazy += 1;
        unlazy(p, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * p, l, mid, ul, ur);
    update(2 * p + 1, mid + 1, r, ul, ur);
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

node query(ll p, ll l, ll r, ll ql, ll qr){
    unlazy(p, l, r);
    if(ql <= l && qr >= r)
        return t[p];
    if(ql > r || qr < l){    
        node x = {0, 0, 0}; 
        return x;
    }
    ll mid = (l + r) / 2;
    node nl = query(2 * p, l, mid, ql, qr);
    node nr = query(2 * p + 1, mid + 1, r, ql, qr);
    return merge(nl, nr);
}

void solve(){
    ll n; cin >> n;
    for(ll i = 0; i < n; i++) cin >> v[i];
    cin >> s;
    build(1, 0, n-1);
    ll q; cin >> q;
    while(q--){
        ll x; cin >> x;
        if(x == 1){
            ll l, r; cin >> l >> r; l--, r--;
            update(1, 0, n-1, l, r);
        }
        else{
            ll g; cin >> g;
            if(g == 0) cout << query(1, 0, n-1, 0, n-1).xor0 << ' ';
            if(g == 1) cout << query(1, 0, n-1, 0, n-1).xor1 << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
