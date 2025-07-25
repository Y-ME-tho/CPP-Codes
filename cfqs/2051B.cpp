#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, a, b, c; cin>>n>>a>>b>>c;
        int sum=a+b+c;
        int day = (n/sum)*3;
        n=n%sum;
        if (n==0) cout<<day<<endl;
        else if (n<=a) cout<<day+1<<endl;
        else if (n<=(a+b)) cout<<day+2<<endl;
        else cout<<day+3<<endl;
    }
}