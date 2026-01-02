#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int q = n%3;
        if (n==1) cout<<0<<endl;
        if (q==0){
            int k = n/3;
            if int m = n/2;
            cout<<(k-m)*2<<endl;
            // else cout<<-1<<endl;
        }else cout<<-1<<endl;
    }
}
