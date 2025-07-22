#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    while (n--){
        long long a,b,k; cin>>a>>b>>k;
        if (a<=k && b<=k) cout<<1<<endl;
        else if (a==b) cout <<1<< endl;
        else if (a / __gcd(a, b) <= k && b / __gcd(a, b) <= k) cout<<1<<endl;
        else cout<<2<<endl;
    }
}