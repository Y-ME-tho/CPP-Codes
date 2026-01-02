#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        string s; cin>>s;
        int gmin=0, lmin=0;
        for (int i=0; i<n;i++){
            if (s[i]=='(') {lmin++; gmin = min(gmin,lmin);}
            else {lmin--; gmin = min(gmin,lmin);}
        }
        cout<<-1*gmin<<endl;
    }
}