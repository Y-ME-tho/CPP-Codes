#include <bits/stdc++.h>
#define int long long
using namespace std; 

int c[1001];
struct X{int f[102];};
vector<X> st;
vector<int> v;
int n,q;

X mrg(X &a,X &b){
    X r;for(int i=0;i<102;i++)r.f[i]=a.f[i]+b.f[i];return r;
}
void bd(int i,int s,int e){
    if(s==e){for(int x=0;x<102;x++)st[i].f[x]=0;st[i].f[v[s]]++;return;}
    int m=(s+e)/2;bd(i*2,s,m);bd(i*2+1,m+1,e);st[i]=mrg(st[i*2],st[i*2+1]);
}
void up(int i,int s,int e,int p,int o,int n){
    if(s>p||e<p)return; 
    if(s==e){
        st[i].f[o]--; 
        st[i].f[n]++; 
        return;
    }
    int m=(s+e)/2;up(i*2,s,m,p,o,n);up(i*2+1,m+1,e,p,o,n);
    st[i]=mrg(st[i*2],st[i*2+1]);
}
X gt(int i,int s,int e,int l,int r){
    if(s>r||e<l){X z;for(int x=0;x<102;x++)z.f[x]=0;return z;}
    if(l<=s&&e<=r)return st[i];
    int m=(s+e)/2;X A=gt(i*2,s,m,l,r),B=gt(i*2+1,m+1,e,l,r);
    return mrg(A,B);
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int x=1;x<=1000;x++){
        int y=x,t=0;while(y>1&&t<101){
            if(y%2==0)y/=2;else y=3*y+1; t++;
        }
        c[x]=min(t,(int)101);
    }

    int T;cin>>T; 
    while(T--){
        cin>>n>>q;
        v.resize(n);st.assign(n*4,{}); 
        for(int i=0;i<n;i++){int x;cin>>x;v[i]=c[x];}
        bd(1,0,n-1);
        while(q--){
            int t;cin>>t;
            if(t==1){
                int l,r,k;cin>>l>>r>>k;--l;--r;
                X z=gt(1,0,n-1,l,r);
                int ans=0;for(int i=k;i<102;i++)ans+=z.f[i];
                cout<<ans<<"\n";
            }else{
                int i;cin>>i;--i; 
                int o=v[i];v[i]=c[ ++v[i]==102?(v[i]=101):v[i] ]; 
                up(1,0,n-1,i,o,v[i]);
            }
        }
    }
    return 0;
}
