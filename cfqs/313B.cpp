#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n= s.length();
    int arr[n+1]={0};
    for (int i=0; i<n; i++){
        if (s[i]==s[i+1]) arr[i+1]=1;
        else arr[i+1]=0;
    }
    for (int i=1; i<=n; i++){
        arr[i]=arr[i-1]+arr[i];
    }
    int m; cin>>m;
    while (m--){
        int l,r; cin>>l>>r;
        cout<<arr[r-1]-arr[l-1]<<endl;
    }
}