#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        long long sum=0, n; cin>>n;
        while (n!=1){
            sum=sum+n;
            n=n/2;
        }
        cout<<sum+1<<endl;
    }

}