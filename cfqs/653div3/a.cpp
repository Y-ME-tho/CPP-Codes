#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--){
        int x,y,n; cin>>x>>y>>n;
        int rem = n%x;
        if (rem==y) cout<<n<<endl;
        else if (rem>y) cout<<n-rem+y<<endl;
        else cout<<n+y-rem -x<<endl;
    }
}
