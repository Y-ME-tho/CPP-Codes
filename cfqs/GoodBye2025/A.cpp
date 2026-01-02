#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--){
        string s; cin>>s;
        int count=0;
        for (char c:s){
            if (c=='Y') count++;
        } 
        cout<<((count>1)?"NO\n":"YES\n");

    }

}