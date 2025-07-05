#include <bits/stdc++.h>
#define int long long
using namespace std;

struct T{int x,y,r;};
struct B{
    size_t operator()(const pair<int,int>&u)const{
        auto a=hash<long long>()((long long)u.first);
        auto b=hash<long long>()((long long)u.second);
        a^=(b+0x9e3779b97f4a7c15ULL+(a<<6)+(a>>2));
        return a;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<T>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y>>v[i].r;
    }
    const int s=200;
    unordered_map<pair<int,int>,vector<int>,B>m;
    m.reserve(n);
    for(int i=0;i<n;i++){
        int px=v[i].x/s,py=v[i].y/s;
        m[{px,py}].push_back(i);
    }
    int ans=0;
    vector<int>d={-1,0,1};
    for(int i=0;i<n;i++){
        int xx=v[i].x,yy=v[i].y,rr=v[i].r;
        int px=xx/s,py=yy/s;
        for(auto dx:d){
            for(auto dy:d){
                auto it=m.find({px+dx,py+dy});
                if(it==m.end())continue;
                for(auto j:it->second){
                    if(j==i)continue;
                    int g=xx-v[j].x,h=yy-v[j].y,u=g*g+h*h,q=rr*rr;
                    if(u<=q)ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
