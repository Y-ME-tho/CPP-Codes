#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; 
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
 
        int ans = -1;
        for (int x = 0; x < 256; x++){
            int xr = 0;
            for (int v : a)
                xr ^= (v ^ x);
            if (xr == 0){
                ans = x;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}