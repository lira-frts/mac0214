#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define muito std::cout.tie(NULL);
#define coxa std::cin.tie(NULL);
#define int long long
#define pb push_back
#define bc push_back
#define all(x) x.begin(),x.end()
using namespace std;

using vll = vector<int>;
using pll = pair<int, int>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

void solve(){
    int k; cin >> k;
    vll cs(k), ps(k);
    for(int &i : cs) cin >> i;
    for(int &i : ps) cin >> i;
    int l, r, mid;
    l = 0, r = 1e9+100;
    while(l <= r){
        mid = (l+r)/2;
        bool macuco = true;
        int qtd = 0;
        for(int i = 0; i < k; i++){
            qtd+=ps[i];
            qtd-=cs[i]*mid;
            if(qtd < 0) macuco = false;
        }
        if(macuco) l = mid+1;
        else r = mid-1;
    } 
    cout << r << '\n';
}

signed main(){
    MAC0214 muito coxa
    int t=1;
    while(t--) solve();
    return 0;
}
