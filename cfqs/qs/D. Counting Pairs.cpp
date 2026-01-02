// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int t; cin>>t;
//     while (t--){
//         int n,x,y; cin>>n>>x>>y;
//         vector<int> v(n+1,0);
//         // vector<long long> hsh(n+1,0);
//         long long sum=0;
//         for (int i=1; i<=n; i++){
//             cin>>v[i];
//             sum+=v[i];
//         }
//         sort (v.begin(), v.end());
        
//         // for (int i=1; i<=n; i++)
//         //     hsh[i] = hsh[i-1]+v[i];

//         int l=1; int r=n, cnt=0;
//         while (l<=n && r<=n){
//             if (sum-v[l]-v[r]>y) r--;
//             else if (sum-v[l]-v[r]<x) l++;
//             else {cnt ++; l++;}
//         }
//         cout<<cnt<<endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--){
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        long long S = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            S += a[i];
        }

        long long L = S - y;
        long long R = S - x;
        sort(a.begin(), a.end());

        long long ans = 0;
        int low = 1, high = n-1;

        for (int i = 0; i < n-1; i++) {
            low  = max(low,  i+1);
            high = max(high, i+1);

            while (low < n && a[low] <  L - a[i]) 
                ++low;

            while (high > i && a[high] > R - a[i]) 
                --high;

            if (high >= low)
                ans += (high - low + 1);
        }

        cout << ans << "\n";
    }
}
