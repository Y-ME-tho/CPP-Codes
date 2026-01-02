#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &v1, vector<long long> &v2, long long mid, long long k){
    long long sum = 0;
    for (long long i=0; i<v1.size();i++){
        if (v2[i]>=mid*v1[i]) continue;
        else if (v2[i]+k>=mid*v1[i]) k = k+v2[i] - mid*v1[i];
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,k; cin>>n>>k;
    vector<long long> v1(n,0), v2(n,0), v3(n,0);
    for (auto &x: v1) cin>>x;
    for (auto &x: v2) cin>>x;
    // for (long long i=0; i<n; i++) v3[i] = v1[i]+v2[i];

    long long lo=0, hi=INT_MAX;
    while(hi-lo>1){
        long long mid = (lo+hi)/2;
        // TTTTTT FFFFF
        if (check(v1,v2, mid, k)) lo = mid;
        else hi = mid-1;
    }
    if (check(v1,v2, hi, k)) cout<<hi<<endl;
    else if (check(v1,v2, lo, k)) cout<<lo<<endl;
    else cout<<-1<<endl;
}