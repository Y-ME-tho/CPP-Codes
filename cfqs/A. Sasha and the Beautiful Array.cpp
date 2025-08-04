#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> v(n,0);
        for (auto &x:v) cin>>x;
        sort(v.begin(), v.end(), greater<int>());
        int sum=0; 
        for (int i=1; i<n; i++){
            sum+=v[i-1]-v[i];
        }
        cout<<sum<<endl;
    }
}