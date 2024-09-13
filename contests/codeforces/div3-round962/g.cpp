#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAXN = 2e5;
const ll INF = 1e9;

struct node{ll minimo, qtd, lazy;} t[4 * MAXN];

node merge(node l, node r){
    if(l.minimo < r.minimo) return l;
    if(r.minimo < l.minimo) return r;
    node x = {l.minimo, l.qtd + r.qtd};
    return x;
}

void build(ll p, ll l, ll r){
    if(l == r){
        t[p] = {0, 1, 0};
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

void unlazy(ll p, ll l, ll r){
    if(t[p].lazy == 0) return;
    t[p].minimo += t[p].lazy;
    if(l != r){
        t[2 * p].lazy += t[p].lazy;
        t[2 * p + 1].lazy += t[p].lazy;
    }
    t[p].lazy = 0;
}

void update(ll p, ll l, ll r, ll ul, ll ur, ll val){
    unlazy(p, l, r);
    if(l > ur || r < ul) return;
    if(l >= ul && r <= ur){
        t[p].lazy = val;
        unlazy(p, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * p, l, mid, ul, ur, val);
    update(2 * p + 1, mid + 1, r, ul, ur, val);
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

node query(ll p, ll l, ll r, ll ql, ll qr){
    unlazy(p, l, r);
    if(ql <= l && qr >= r)
        return t[p];
    if(ql > r || qr < l){    
        node x = {INF, 0, 0}; 
        return x;
    }
    ll mid = (l + r) / 2;
    node nl = query(2 * p, l, mid, ql, qr);
    node nr = query(2 * p + 1, mid + 1, r, ql, qr);
    return merge(nl, nr);
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> amizades(m);
    vector<vector<ll>> inicio(n), fim(n);
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b; a--, b--;
        amizades[i] = {a, b};
        inicio[a].push_back(i);
        fim[b].push_back(i);
    }
    build(1, 0, n - 1);
    for(ll i = 0; i < m; i++) update(1, 0, n - 1, amizades[i].first, amizades[i].second - 1, 1);
    ll qtd_usada = query(1, 0, n - 1, 0, n - 1).qtd;
    ll resp = n - qtd_usada;
    for(ll i = 0; i < n; i++){
        for(ll j: inicio[i]){
            update(1, 0, n - 1, amizades[j].first, amizades[j].second - 1, -1);
            update(1, 0, n - 1, amizades[j].second, n - 1, 1);
            update(1, 0, n - 1, 0, amizades[j].first - 1, 1);
        }
        for(ll j: fim[i]){
            update(1, 0, n - 1, amizades[j].first, amizades[j].second - 1, 1);
            update(1, 0, n - 1, amizades[j].second, n - 1, -1);
            update(1, 0, n - 1, 0, amizades[j].first - 1, -1);
        }
        ll qtd_usada = query(1, 0, n - 1, 0, n - 1).qtd;
        resp = min(resp, n - qtd_usada);
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
