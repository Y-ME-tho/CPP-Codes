#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n,0), b(n,0), c(n,0);
    for (auto &it: a) cin>>it;
    for (auto &it: b) cin>>it;
    for (int i=0; i<n; i++) c[i] = a[i]-b[i];
    sort (c.begin(), c.end());

    int pos = upper_bound(c.begin(), c.end(), 0) - c.begin();
    long long no=0;
    for (int i=0; i<n; i++){
        int k = lower_bound(c.begin()+i+1, c.end(), -c[i]+1) - c.begin();
        no = no+ n-k;
    }
    cout<<no<<endl;

}