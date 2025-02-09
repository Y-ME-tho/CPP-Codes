#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, a, b, c, s, d;
        cin>>n >>a >>b >>c;
        s=a+b+c;
        d=n/s;
        n%=s;
        while (n>=0){
            n-=a; d+=1;
            if (n>=0) n-=b; d+=1;
            if (n>=0) n-=c; d+=1;    
        }
        cout<<d<<"\n";
    }
}   


// typedef long long ll;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int>a(n);
//         for(auto &x:a) cin>>x;
//         bool has_zero=false;
//         int zero_count=0;
//         for(auto x:a) if(x==0){has_zero=true; zero_count++;}
//         if(!has_zero){
//             int mn = INT32_MAX, idx=-1;
//             for(int i=0;i<n;i++) if(a[i]<mn){mn=a[i]; idx=i;}
//             a[idx]++;
//             ll prod=1;
//             for(auto x:a) prod *=x;
//             cout<<prod<<"\n";
//         }
//         else{
//             if(zero_count>=2){
//                 cout<<0<<"\n";
//             }
//             else{
//                 // zero_count ==1
//                 int idx=-1;
//                 for(int i=0;i<n;i++) if(a[i]==0){idx=i; break;}
//                 a[idx]=1;
//                 bool still_zero=false;
//                 for(auto x:a) if(x==0){still_zero=true; break;}
//                 if(still_zero) cout<<0<<"\n";
//                 else{
//                     ll prod=1;
//                     for(auto x:a) prod *=x;
//                     cout<<prod<<"\n";
//                 }
//             }
//         }
//     }
// }


// #include <bits/stdc++.h>
// using namespace std;

// // bool comp(int a, int b) {
// //     return a > b;
// // }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int>a(n);
//         int ab = 0;
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
//         sort(a.begin(), a.end());
//         while (next_permutation (a.begin(), a.end())){
//             if (a[2]>a[0]){
//                 if (a[1]>a[3]) {
//                     ab+=1;
//                 }
//             }        
//         }
//         cout<<ab<<endl;
//         // do {
//         //     if (a[2]>a[0]){
//         //         if (a[1]>a[3]){
//         //             ab+=1;
//         //         }
//         //     }

//         // }while (next_permutation(a.begin(), a.end()));
//         // cout<<ab<<endl;   
//     }
// }   

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         int l, r;
//         cin >> l >> r;
//         if (l == r) {
//             if (l % 2 == 0) cout << l/2 << " " << l/2 << "\n";
//             else cout << "-1\n";
//         }
//         else if (r >= 2*l) {
//             cout << l << " " << l << "\n";
//         }
//         else {
//             if (r % 2 == 0) cout << r/2 << " " << r/2 << "\n";
//             else cout << (r-1)/2 << " " << (r-1)/2 << "\n";
//         }
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int bit[5005];

// void update(int idx, int val, int n) {
//     while (idx <= n) {
//         bit[idx] += val;
//         idx += idx & (-idx);
//     }
// }

// int query(int idx) {
//     int sum = 0;
//     while (idx > 0) {
//         sum += bit[idx];
//         idx -= idx & (-idx);
//     }
//     return sum;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> p(n);
//         for (int i = 0; i < n; i++) {
//             cin >> p[i];
//         }
//         int count = 0;
//         for (int b = 0; b < n-2; b++) {
//             memset(bit, 0, sizeof(bit));
//             for (int d = n-1; d > b; d--) {
//                 for (int c = d-1; c > b; c--) {
//                     if (p[c] > p[b]) {
//                         count += query(p[c]);
//                     }
//                 }
//                 if (p[d] < p[b]) {
//                     update(p[d], 1, n);
//                 }
//             }
//         }
//         cout << count << "\n";
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 998244353;

// long long solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 0; i < n; i++) cin >> b[i];
    
//     int m;
//     cin >> m;
//     vector<int> c(m), d(m);
//     for(int i = 0; i < m; i++) cin >> c[i];
//     for(int i = 0; i < m; i++) cin >> d[i];
    
//     // Check if Y divides X
//     int j = 0;
//     for(int i = 0; i < m && j < n; i++) {
//         if(c[i] == a[j]) {
//             if(d[i] > b[j]) return 0;
//             j++;
//         }
//         else if(c[i] < a[j]) return 0;
//     }
//     if(j < m) return 0;
    
//     long long result = 1;
//     j = 0;
//     for(int i = 0; i < n; i++) {
//         int exp = b[i];
//         if(j < m && a[i] == c[j]) {
//             exp -= d[j];
//             j++;
//         }
//         result = (result * (exp + 1)) % MOD;
//     }
    
//     return result;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout << solve() << "\n";
//     return 0;
// }





