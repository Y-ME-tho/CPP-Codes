#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;
        int zero=0, one=0;
        for (int i=0; i<n;i++){
            if (s[i]=='1') one++;
            else zero++;
        }
        if (one - zero>k) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}