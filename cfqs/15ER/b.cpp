#include <bits/stdc++.h>
using namespace std;

// bool check(long long mid, vector<long long> &v1, vector<long long> &v2){
//     vector<long long> v(v1.size(),0);
//     long long k=0;
//     for (long long i=0; i<v2.size(); i++){
//         while (v2[i]-mid<=v1[k]) {v[k]++; k++;}
//         while (v2[i]+mid >= v1[k]) {v[k]++; k++;}
//     }
//     for (auto x: v){
//         if (x==0) return false;
//     }
//     return true;
// }

bool check(long long mid, vector<long long>& v1, vector<long long>& v2) {
    long long k = 0, n = v1.size(), m = v2.size();

    for (long long i = 0; i < m && k < n; i++) {
        while (k < n && v1[k] >= v2[i] - mid && v1[k] <= v2[i] + mid) {
            k++;
        }
    }
    return (k == n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m; cin>>n>>m;
    vector<long long> v1(n,0), v2(m,0), v3(n,0);
    for (auto &x: v1) cin>>x;
    for (auto &x: v2) cin>>x;
    long long lo=0, hi=2e9+5, mid=(lo+hi)/2;
    while (hi-lo>1){
        mid = (lo+hi)/2;
        if (check(mid, v1, v2)) hi=mid;
        else lo=mid+1;
    }
    if (check(lo, v1, v2)) cout<<lo<<endl;
    else cout<<hi<<endl;
}