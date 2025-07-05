#include <bits/stdc++.h>
#define int long long
using namespace std;
int M=998244353,p2[5001],b[101][101],cC[101],dp[101][101];
int32_t main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    p2[0]=1;for(int i=1;i<=5000;i++)p2[i]=(p2[i-1]*2)%M;
    for(int i=0;i<=100;i++){b[i][0]=1;for(int j=1;j<=i;j++)b[i][j]=(b[i-1][j-1]+b[i-1][j])%M;}

    cC[1]=1;for(int i=2;i<=100;i++){
        int x=p2[i*(i-1)/2];
        for(int m=1;m<i;m++){
            int t=b[i-1][m-1]*cC[m]%M;
            t=(t*p2[(i-m)*(i-m-1)/2])%M;
            x=(x-t+M)%M;
        }
        cC[i]=x;
    }

    dp[0][0]=1;
    for(int i=1;i<=100;i++){
        for(int k=1;k<=i;k++){
            int s=0;
            for(int m=1;m<=i;m++){
                s=(s + b[i-1][m-1]*cC[m]%M*dp[i-m][k-1])%M;
            }
            dp[i][k]=s;
        }
    }
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;cout<<dp[n][k]<<'\n';
    }
    return 0;
}
