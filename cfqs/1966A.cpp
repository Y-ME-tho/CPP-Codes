#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, no; cin>>n;
        no=n/4;
        n=n%4;
        no += n/2;
        cout<<no<<endl;
    }
}