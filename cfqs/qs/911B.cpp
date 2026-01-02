#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b; cin>>n>>a>>b;
    int lo=1, hi=a+b;
    int ma=1,mid;
    while (hi-lo>1){
        mid = (lo+hi)/2;
        int k = min(a/mid , b/(n-mid));

        // int me = max(k, me);
        if(k>ma){
            lo = mid;
            ma = max(k, ma);
        }else{
            hi = mid-1;
        }
    }
    cout<<ma <<'\n' ;
}