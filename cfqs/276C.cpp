#include <bits/stdc++.h>
using namespace std;
const  int N = 2e5+10;
long long int arr[N], pf[N];

int main(){
    int n,q; cin>>n>>q;
    for (int i=1; i<=n;i++){
        cin>>arr[i];
    }
    for (int i=1; i<=q;i++){
        int l,r; cin>>l>>r;
        pf[l]++;
        pf[r+1]--;
    }
    for(int i=1; i<=n; i++){
        pf[i]=pf[i-1]+pf[i];
    }
    sort(pf+1, pf+n+1);
    sort(arr+1, arr+n+1);

    long long int sum=0;
    for(int i=1; i<=n; i++){
        sum+=arr[i]*pf[i];
    }
    cout<<sum<<endl;
}