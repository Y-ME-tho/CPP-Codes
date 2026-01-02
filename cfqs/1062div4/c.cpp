#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int odd=0, even=0;
        vector<int> v(n,0);
        for (auto &x:v) {cin>>x; (x%2?odd++:even++);}
        if (odd==0 || even ==0){
            for (auto x: v) cout<<x<<' ';
            cout<<endl;
        }
        else{
            sort(v.begin(), v.end());
            for (auto x: v) cout<<x<<' ';
            cout<<endl;
        }

    }
}