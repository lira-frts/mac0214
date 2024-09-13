#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

struct node{int v[26][2];} t[4 * MAXN];
string a, b;

node merge(node l, node r){
    node x;
    for(int i = 0; i < 26; i++){
        x.v[i][0] = l.v[i][0] + r.v[i][0];
        x.v[i][1] = l.v[i][1] + r.v[i][1];
    }
    return x;
}

void build(int p, int l, int r){
    if(l == r){
        for(int i = 0; i < 26; i++) t[p].v[i][0] = 0, t[p].v[i][1] = 0;
        t[p].v[a[l] - 'a'][0] = 1;
        t[p].v[b[l] - 'a'][1] = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    
    t[p] = merge(t[2 * p], t[2 * p + 1]);
}

node query(int p, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r)
        return t[p];

    if(ql > r || qr < l){    
        node x; 
        for(int i = 0; i < 26; i++) x.v[i][0] = 0, x.v[i][1] = 0;
        return x;
    }

    int mid = (l + r) / 2;
    node nl = query(2 * p, l, mid, ql, qr);
    node nr = query(2 * p + 1, mid + 1, r, ql, qr);
    return merge(nl, nr);
}

void solve(){
    int n, q; cin >> n >> q;
    cin >> a >> b;
    build(1, 0, n - 1);
    while(q--){
        int ql, qr; cin >> ql >> qr;
        node x = query(1, 0, n - 1, ql - 1, qr - 1);
        int cont = 0;
        for(int i = 0; i < 26; i++) cont += abs(x.v[i][0] - x.v[i][1]);
        cout << cont / 2 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}