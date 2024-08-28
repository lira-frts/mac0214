#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll t; cin >> t;
    while(t--){
        ll m1 = 333, m2 = 666;
        while(m1 != m2){
            cout << "?" << m1 << m2;
            ll resp; cin >> resp;
            if(m1 * m2 == resp){m1 = m2 + (999 - m2) / 3; m2 += 2 * (999 - m2) / 3;}
            else if(m1 * (m2 + 1) == resp){ll aux = m2 - m1; m1 += aux / 3; m2 += 2 * aux / 3;}
            else{m2 = 2 * m1 / 3; m1 /= 3;}

        }
        cout << m1 << endl;
    }

    return 0;
}
