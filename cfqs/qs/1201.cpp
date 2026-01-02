#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k; cin>>n>>k;
    vector<long long> v(n,0);
    for (auto &x:v) cin>>x;
    sort(v.begin(), v.end());
    long long lo=v[(n)/2], hi=2e9;
    long long mid = (lo+hi)/2;
    while (lo<hi){
        long long sum=0;
        mid = (lo+hi+1)/2;
        for (long long i=n/2; i<n; i++){
            sum+=max(0LL, mid-v[i]);
        }
        if (sum<=k) lo=mid;
        else hi = mid-1;
    }
    cout<<lo<<endl;

}