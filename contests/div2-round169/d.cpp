#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAX = 200000;
const ll INF = 1234567890;

vector<ll> s;
set<ll> BR, BG, BY, GY, GR, RY;

ll a, b, dist;

void atualiza_dist(set<ll> &x){
    set<ll>::iterator lower, upper;
    lower = x.lower_bound(a);
    if(lower != x.begin()){
        ll x = *(--lower); dist = min(dist, abs(a-x)+abs(b-x));
    }
    upper = x.upper_bound(a);
    if(upper != x.end()){
        ll x = *(upper); dist = min(dist, abs(a-x)+abs(b-x));
    }
    lower = x.lower_bound(b);
    if(lower != x.begin()){
        ll x = *(--lower); dist = min(dist, abs(a-x)+abs(b-x));
    }
    upper = x.upper_bound(b);
    if(upper != x.end()){
        ll x = *(upper); dist = min(dist, abs(a-x)+abs(b-x));
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n, q; cin >> n >> q;

        for(ll i = 0; i < n; i++){
            string ss; cin >> ss;
        
            if(ss == "BR"){s.push_back(0); BR.insert(i);}
            if(ss == "BG"){s.push_back(1); BG.insert(i);}
            if(ss == "BY"){s.push_back(2); BY.insert(i);}
            if(ss == "GY"){s.push_back(3); GY.insert(i);}
            if(ss == "GR"){s.push_back(4); GR.insert(i);}
            if(ss == "RY"){s.push_back(5); RY.insert(i);}
        }

        for(ll i = 0; i < q; i++){
            cin >> a >> b; a--; b--;
            ll aa = s[a], bb = s[b];
            if((aa == 0 && bb != 3) || (aa == 1 && bb != 5) || (aa == 2 && bb != 4) ||
               (aa == 3 && bb != 0) || (aa == 4 && bb != 2) || (aa == 5 && bb != 1)) cout << abs(a - b) << '\n';

            // caso em que as 4 letras são diferentes
            else{
                dist = INF;
                if(s[a] != 0 && s[b] != 0) atualiza_dist(BR);
                if(s[a] != 1 && s[b] != 1) atualiza_dist(BG);
                if(s[a] != 2 && s[b] != 2) atualiza_dist(BY);
                if(s[a] != 3 && s[b] != 3) atualiza_dist(GY);
                if(s[a] != 4 && s[b] != 4) atualiza_dist(GR);
                if(s[a] != 5 && s[b] != 5) atualiza_dist(RY);
                cout << (dist == INF ? -1 : dist) << '\n';
            } 
        }
        
        s.clear(); BR.clear(); BG.clear(); BY.clear(); GY.clear(); GR.clear(); RY.clear();
    }

    return 0;
}
