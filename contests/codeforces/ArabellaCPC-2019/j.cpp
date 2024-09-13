#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll NMAX = 2e5;

ll pd[NMAX];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s; ll n = s.size();
    pd[0] = min(s[0] - '0', 1 + 10 - (s[0] - '0'));
    for(ll i = 1; i < n; i++) pd[i] = min(pd[0] + s[i] - '0', pd[0] - 1 + 10 - (s[i] - '0'));
    cout << pd[n - 1] << '\n';
}
