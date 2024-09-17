/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAXN = 2e5+1;

struct node{ll pos, lazy;} t[4 * MAXN];
vector<ll> v(MAXN);

node merge(node l, node r){
    node x = {l.pos + r.pos, 0};
    return x;
}

void build(ll p, ll l, ll r){
    if(l == r){
        t[p].pos = {v[l]};
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

void unlazy(ll p, ll l, ll r){
    if(t[p].lazy == 0) return;
    t[p].pos = (r - l + 1) * t[p].lazy;
    if(l != r){
        t[2 * p].lazy = t[p].lazy;
        t[2 * p + 1].lazy = t[p].lazy;
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
        node x = {0, 0}; 
        return x;
    }
    ll mid = (l + r) / 2;
    node nl = query(2 * p, l, mid, ql, qr);
    node nr = query(2 * p + 1, mid + 1, r, ql, qr);
    return merge(nl, nr);
}

void solve(){
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++){   
        ll a; cin >> a; v[i] = a - i;
    }
    build(1, 1, n);
    ll q; cin >> q;
    ll resp = 0;
    while(q--){
        ll t, g; cin >> t >> g; g -= t;

        ll pos_atual = query(1, 1, n, t, t).pos;

        // vai pra direita
        if(pos_atual < g){
            
            // vamos ter que fazer busca binária pra ver quem tbm vai ter que ir pra direita
            ll inicio = t, fim = n;
            while(inicio <= fim){
                ll meio = (inicio + fim) / 2;
                ll posicao_meio = query(1, 1, n, meio, meio).pos;
                if(posicao_meio <= g) inicio = meio + 1;
                else fim = meio - 1;
            }
            // no final, fim é o último cara que vai ter quer ir pra direita
            resp += -query(1, 1, n, t, fim).pos + g * (fim - t + 1);
            update(1, 1, n, t, fim, g);
        }

        // vai pra esquerda (comunista)
        else{
            
            // busca binária dnv
            ll inicio = 1, fim = t;
            while(inicio <= fim){
                ll meio = (inicio + fim) / 2;
                ll posicao_meio = query(1, 1, n, meio, meio).pos;
                if(posicao_meio >= g) fim = meio - 1;
                else inicio = meio + 1;
            }
            // no final, inicio é o último cara que vai ter que ir pra esquerda
            resp += query(1, 1, n, inicio, t).pos - g * (t - inicio + 1);
            update(1, 1, n, inicio, t, g);
        }
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    // cin >> t;
    
    while(t--) solve();
}
