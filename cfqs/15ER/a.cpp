#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin>>n;
    vector<long long> v(n,0);
    for (auto &x: v) cin>>x;
    long long s=1, max1=1;
    for (long long i=1; i<n; i++){
        if (v[i]>v[i-1]) {s++; max1=max(s, max1);}
        else s=1;
        max1=max(s, max1);
    }
    cout<<max1<<endl;
}