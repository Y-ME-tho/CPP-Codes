#include <bits/stdc++.h>
#define int long long
using namespace std;

int spf(int x){
    if(x%2==0) return 2;
    if(x%3==0) return 3;
    for(int i=5;i*i<=x;i+=6){
        if(x%i==0) return i;
        if(x%(i+2)==0) return i+2;
    }
    return x;
}

void solve(){
    int n;cin>>n;
    vector<int>a(n);bool one=false;int s=0,m=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i];s+=a[i];
        if(a[i]==1) one=true;
    }
    if(one){cout<<s<<"\n";return;}
    for(int i=0;i<n;i++){
        int f=spf(a[i]);
        if(f<m) m=f;
        if(m==2) break;
    }
    cout<<m+(n-1)<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;while(t--) solve();
    return 0;
}
