#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> v(n+1,0);
        for (long long i=1;i<=n; i++) cin>>v[i];

        vector<long long> v1(n+1,0);
        for (long long i=1; i<=n; i++) v1[i]=v[i]+v1[i-1];

        vector<long long> v2(n+1,0);
        for (long long i=2; i<=n; i++) v2[i]=v2[i-1]+llabs(v[i]);

        long long sumn = -(v1[n]-v1[1]);

        for (long long i=2; i<=n; i++){
            long long pfs = v2[i-1];
            long long sfs = v1[n]-v1[i];
            sumn = max(sumn, v[1] + pfs - sfs);
        }
        cout<<sumn<<'\n';
    }
}
