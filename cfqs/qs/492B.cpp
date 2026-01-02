#include <bits/stdc++.h>
using namespace std;

bool radius(vector<int> &v, double r, int l){
    for (int i=1; i<v.size()-1; i++){
        if (v[i]+2*r>=v[i+1]) continue;
        else return false;
    }
    if (v[v.size()-1]+r>=l && v[1]-r<=0) return true;
    else return false;
}
// FFFFFF TTTTT

int main(){
    int n, l; cin>>n>>l;
    vector<int> v(n+1,0);
    for (int i=1; i<=n; i++) cin>>v[i];
    sort(v.begin(), v.end());

    double lo=0,hi=l, mid;
    // while (hi-lo>1e-10){
    for (int it = 0; it < 70; ++it) {
        mid = (hi+lo)/2;
        if (radius(v,mid,l)) hi=mid;
        else lo=mid;
    }
    if (radius (v,lo,l)) cout << fixed << setprecision(10) << lo<< endl;
    else cout<<fixed << setprecision(10)<<hi<<endl;
}