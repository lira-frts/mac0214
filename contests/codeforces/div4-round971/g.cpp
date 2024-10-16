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

const ll MAXN = 2e5;

struct node{ll v, lazy;} t[4 * MAXN];

node merge(node l, node r){
    node x = {l.v + r.v, -1};
    return x;
}

void build(ll p, ll l, ll r){
    if(l == r){
        t[p] = {0, -1};
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

void unlazy(ll p, ll l, ll r){
    if(t[p].lazy == -1) return;
    t[p].v = t[p].lazy * (r - l + 1);
    if(l != r){
        t[2 * p].lazy = t[p].lazy;
        t[2 * p + 1].lazy = t[p].lazy;
    }
    t[p].lazy = -1;
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
        node x = {0, -1}; 
        return x;
    }
    ll mid = (l + r) / 2;
    node nl = query(2 * p, l, mid, ql, qr);
    node nr = query(2 * p + 1, mid + 1, r, ql, qr);
    return merge(nl, nr);
}

void solve(){
    ll n, k, q; cin >> n >> k >> q;
    vll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i], v[i] -= i;    

    // cálculo para os de tamanho exatamente k
    vll vk(n-k+1);
    map<ll, ll> mp;
    multiset<ll> ms;
    for(ll i = 0; i < k; i++){
        ll x = v[i];
        if(mp[x] != 0) ms.erase(ms.find(mp[x]));
        mp[x]++;
        ms.insert(mp[x]);
    }
    vk[0] = k - *ms.rbegin();
    for(ll i = k; i < n; i++){
        ll x = v[i-k];
        ms.erase(ms.find(mp[x]));
        mp[x]--;
        if(mp[x] != 0) ms.insert(mp[x]);
        ll y = v[i];
        if(mp[y] != 0) ms.erase(ms.find(mp[y]));
        mp[y]++;
        ms.insert(mp[y]);
        vk[i-k+1] = k - *ms.rbegin();
    }

    // leitura queries e ordena do maior l para o menor
    vvll qs(q);
    for(ll i = 0; i < q; i++){
        ll l, r; cin >> l >> r; l--, r--;
        qs[i] = {l, r, i};
    }
    sort(qs.rbegin(), qs.rend());

    // resto
    vll resp(q);
    stack<pll> s; s.push({vk[n-k], n-k});
    ll atual = n-k;
    build(1, 0, n-k);
    update(1, 0, n-k, atual, atual, vk[atual]);
    for(ll i = 0; i < q; i++){
        ll l = qs[i][0], r = qs[i][1], ind = qs[i][2];
        while(atual != l){
            atual--;
            ll ultimo = atual; 
            while(!s.empty() && s.top().first > vk[atual]){
                ultimo = s.top().second;
                s.pop();
            }
            s.push({vk[atual], ultimo});
            update(1, 0, n-k, atual, ultimo, vk[atual]);
        }
        resp[ind] = query(1, 0, n-k, l, r-k+1).v;
    }

    for(ll i = 0; i < q; i++) cout << resp[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
