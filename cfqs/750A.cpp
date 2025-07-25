#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> &v, int min){
    int l=0; int h = v.size()-1;
    int mid;
    while (h-l>1){
        mid = (h+l)/2;
        if (v[mid]<=min) l=mid;
        else h=mid-1;
    }
    if (v[h]<=min) return h;
    else if (v[l]<=min) return l;
    else return 0;

}

int main(){
    int n, k; cin>>n>>k;
    int min=240-k;
    vector<int> v(n+1, 0);
    for (int i=1; i<=n; i++) v[i]= 5*i;
    for (int i=1; i<=n;  i++) v[i] = v[i] + v[i-1];
    int q = binarysearch(v, min);
    cout<<q<<endl;
}