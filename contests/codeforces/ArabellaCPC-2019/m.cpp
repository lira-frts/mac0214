#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
#define vetor vector<ll>
#define pb push_back
#define bc back
 
#define all(x) x.begin(),x.end()
 
#define NO {cout << "NO" << "\n";}
#define YES {cout << "YES" << "\n";}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    map<char, int> mp;
 
    string recebe;
 
    cin >> recebe;
    for(ll i=0; i<recebe.size(); i++){
        if(mp.count(recebe[i])>0){
            mp[recebe[i]]++;
        }
        else{
            mp[recebe[i]]=1;
        }
    }
 
    for(int i=97; i<122; i++){
        if(mp[(char)i]>=2){
            while(mp[(char)i]>=2){
                mp[(char)i]=mp[(char)i]-2;
                mp[(char)(i+1)]=mp[(char)(i+1)]+1;
            }
        }
    }
    recebe.clear();
    recebe="";
 
    for(int i=122; i>=97; i--){
        if(mp[(char)i]>0){
            while(mp[(char)i]>0){
                mp[(char)i]=mp[(char)i]-1;
                recebe+=(char)i;
            }
        }
    }
    cout << recebe << "\n";
 
    recebe.clear();    
 
    return 0;
}
