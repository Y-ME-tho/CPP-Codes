#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d; cin>>n>>d;
    vector<pair<int, int>> v(n);
    for (auto &it:v) cin>>it.first>>it.second;

    sort(v.begin(), v.end());
    vector<long long> hsh(n+1,0);
    for (int i=0; i<n; i++){
        hsh[i+1] = hsh[i] + v[i].second;
    }
    int l=0, r = lower_bound(v.begin(), v.end(), make_pair(v[0].first+d, 0)) - v.begin();
    long long sum=hsh[r] - hsh[l];
    while (r<n){
        if (v[r].first- v[l].first >=d) l++;            
        else r++;
        sum = max(sum , hsh[r]-hsh[l]);
    }
    cout<<sum<<"\n";
}