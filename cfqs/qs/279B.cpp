#include <bits/stdc++.h>
using namespace std;
// vector<int> v(1e5+10, 0);

int main(){
    int n,t; cin>>n>>t;
    vector<int> v(n+1,0);
    vector<int> hsh(n+1,0);

    for (int i=1; i<n+1; i++) cin>>v[i];
    for (int i=1; i<n+1; i++) hsh[i]=hsh[i-1]+v[i];

    int l=1, r=1;
    int no=0;
    while (l<=r && r<=n){
        if (hsh[r]-hsh[l-1]>t) l++;
        else r++;
        no=max(no, r-l);
    }
    cout<<no<<endl;






    // int no=0, sum=0;
    // int ts=0, tno=0;

    // for (auto it: v){
    //     ts+=it;
    //     if (ts<=t){
    //         tno++;
    //     }else{
    //         ts=0;
    //         tno=0;
    //     }
    //     if (tno>no){
    //         no=tno;
    //     }
    // }
    // cout<<no<<endl;
}