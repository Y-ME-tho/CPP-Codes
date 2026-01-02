#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int root = sqrt(n);
        if (root * root ==n) cout<<root<<" "<<0<<endl;
        else cout<<-1<<endl;
    }
}