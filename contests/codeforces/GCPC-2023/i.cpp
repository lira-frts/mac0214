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

signed main(){
    MAC0214 muito coxa
    int n, q, sapo=1; cin >> n;
    vll vet(n+1, 0); 
    vll pulos;
    set<int> freeFoia;
    for(int i = 0; i < 2*1e6; i++){
        freeFoia.insert(i+1);
    }
    for(int i=0; i<n; i++){
        int in;
        cin >> in;
        vet[i+1]=in;
        freeFoia.erase(in);
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int jp; cin >> jp;
        int ans = *freeFoia.upper_bound(vet[jp]);
        cout << ans << '\n';
        freeFoia.insert(vet[jp]);
        freeFoia.erase(ans);
        vet[jp] = ans;
    }
    
    return 0;
}
