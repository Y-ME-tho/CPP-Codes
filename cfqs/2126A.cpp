#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for (int i=0; i<t; i++){
        int n,k=9; cin>>n;
        n=abs(n);
        while (n>0){
            if (k>n%10) k=n%10;
            n/=10;
        }
        cout<<k<<endl;
    }
}