#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> v(n+2, 0);
        for (long long i=1; i<=n; i++) cin>>v[i];
        long long sum=0;
        for (long long i=2; i<=n; i=i+2){
            if (v[i-1]>v[i]){
                sum+=v[i-1]-v[i];
                v[i-1]-=(v[i-1]-v[i]);
            }
            if (v[i+1]>v[i]){
                sum+=v[i+1]-v[i];
                v[i+1]-=(v[i+1]-v[i]);
            }
        }
        cout<<sum<<endl;
    }

}