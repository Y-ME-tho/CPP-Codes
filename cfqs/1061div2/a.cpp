#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--){
        long long n; cin>>n;
        long long k=0;
        long long m=n;
        while (m>=3){
            k+=m/3;
            m= (m+2)/3;
        }
        cout<<k<<endl;
    }
}
