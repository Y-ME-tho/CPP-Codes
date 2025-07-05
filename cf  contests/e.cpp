#include <bits/stdc++.h>
#define int long long
using namespace std;
int c(const string&s,int a,int l1,int b,int l2){
    int m=min(l1,l2);
    for(int i=0;i<m;i++){
        if(s[a+i]<s[b+i])return -1;
        if(s[a+i]>s[b+i])return 1;
    }
    if(l1<l2)return -1;
    if(l1>l2)return 1;
    return 0;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int f=0;
        for(int i=1;i<=3&&i<n-1&&!f;i++){
            for(int j=i+1;j<=min((int)(n-1),(int)(i+3))&&!f;j++){
                string x=s.substr(0,i),y=s.substr(i,j-i),z=s.substr(j);
                if(!z.empty()){
                    if(c(s,i,j-i,0,i)==-1&&c(s,0,i,j,n-j)==-1){
                        cout<<x<<" "<<y<<" "<<z<<"\n";
                        f=1;
                        break;
                    }
                }
            }
        }
        if(!f)cout<<"-1\n";
    }
    return 0;
}
