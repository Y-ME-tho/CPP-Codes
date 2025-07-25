#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, a1=0, a2=0, a3=0;
    cin>>n;
    for (int i=0; i<n; i++) {cin>>a; a1^=a;}
    for (int i=0; i<n-1; i++) {cin>>a; a2^=a;}
    cout<<(a1^a2)<<endl;
    for (int i=0; i<n-2; i++) {cin>>a; a3^=a;}
    cout<<(a2^a3)<<endl;
}