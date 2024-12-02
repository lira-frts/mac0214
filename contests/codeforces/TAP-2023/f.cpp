#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define muito std::cout.tie(NULL);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

using vll = vector<int>;
using pll = pair<int, int>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

void solve(){
    int n; cin >> n;
    int w, l, tx, ty; cin >> w >> l >> tx >> ty;
    vpll va(n), vr(n);
    for(auto &[x, y]: va) cin >> x >> y;
    for(auto &[x, y]: vr) cin >> x >> y;
    int minimoA = 1e18, minimoR = 1e18;
    int cont = 0;
    for(auto &[x, y]: va){
        int dist = (x-tx)*(x-tx)+(y-ty)*(y-ty);
        if(dist < minimoA) minimoA = dist;
    }
    for(auto &[x, y]: vr){
        int dist = (x-tx)*(x-tx)+(y-ty)*(y-ty);
        if(dist < minimoR) minimoR = dist;
    }
    if(minimoA < minimoR){
        for(auto &[x, y]: va){
            int dist = (x-tx)*(x-tx)+(y-ty)*(y-ty);
            if(dist < minimoR) cont++;
        }
        cout << "A " << cont << '\n';
    }
    else{
        for(auto &[x, y]: vr){
            int dist = (x-tx)*(x-tx)+(y-ty)*(y-ty);
            if(dist < minimoA) cont++;
        }
        cout << "R " << cont << '\n';
    }
}

signed main(){
    MAC0214 muito coxa
    int t = 1;
    while(t--) solve();
    return 0;
}
