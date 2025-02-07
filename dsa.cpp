// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false); 
//     cin.tie(nullptr);

//     long long t; 
//     cin >> t;
//     while(t--) {
//         long long n; 
//         cin >> n;
//         long long m=1;
//         long long k = INT16_MAX;
//         long long c=0;
//         vector<long long> a(n);
//         for(long long i = 0; i < n; ++i){ 
//             cin >> a[i];
//             if (a[i]<=k) k=a[i];
//         }
//         for(long long i = 0; i < n; ++i){
//             if (a[i]==k){
//                 if (c==0){
//                     a[i]+=1; c+=1;
//                 }
//             }
//             m*=a[i];
//         }
//     cout<< m <<"\n";
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

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

// int main() {
//     ios::sync_with_stdio(false); 
//     cin.tie(nullptr);

//     int t; 
//     cin >> t;
//     while(t--) {
//         int n; 
//         cin >> n;
//         vector<long long> a(n);
//         for(int i = 0; i < n; ++i) 
//             cin >> a[i];

//         long long P = 0;
//         bool ok = true;
//         for(int j = 0; j < n; ++j) {
//             if(j % 2 == 0) { 
//                 P += a[j];
//                 if(P < 0) { ok = false; break; }
//             } else { 
//                 P -= a[j];
//                 if(P > 0) { ok = false; break; }
//             }
//         }
//         cout << (ok ? "YES\n" : "NO\n");
//     }
//     return 0;
// }


// struct DSU {
//     vector<int> parent, sz;
//     DSU(int n) : parent(n+1), sz(n+1,1) {
//         iota(parent.begin(), parent.end(), 0);
//     }
//     int find(int a) {
//         return parent[a] == a ? a : (parent[a] = find(parent[a]));
//     }
//     bool union_set(int a, int b) {
//         a = find(a), b = find(b);
//         if(a == b) return false;
//         if(sz[a] < sz[b]) swap(a,b);
//         parent[b] = a;
//         sz[a] += sz[b];
//         return true;
//     }
// };
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, m1, m2;
//         cin >> n >> m1 >> m2;
//         vector<pair<int,int>> edgesF(m1);
//         for(auto &[u, v] : edgesF) cin >> u >> v;
//         DSU dsuG(n);
//         for(int i = 0; i < m2; i++) {
//             int u, v;
//             cin >> u >> v;
//             dsuG.union_set(u,v);
//         }

//         vector<bool> seen(n+1);
//         int c_G = 0;
//         for(int v = 1; v <= n; v++) {
//             int root = dsuG.find(v);
//             c_G += !seen[root];
//             seen[root] = true;
//         }
//         DSU dsuF(n);
//         long long removals = 0;
//         for(auto [u, v] : edgesF) {
//             removals += (dsuG.find(u) != dsuG.find(v));
//             if(dsuG.find(u) == dsuG.find(v)) dsuF.union_set(u,v);
//         }
//         fill(seen.begin(), seen.end(), false);
//         int num_comp_F = 0;
//         for(int v = 1; v <= n; v++) {
//             int root = dsuF.find(v);
//             num_comp_F += !seen[root];
//             seen[root] = true;
//         }

//         cout << removals + num_comp_F - c_G << '\n';
//     }
// }


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);


//     int t;
//     cin >> t;
//     while(t--){
//         int n, m;
//         cin >> n >> m;
//         vector<int> rem(n), perm(n);
//         bool possible = true;

//         for(int i = 0; i < n && possible; ++i){
//             int first_rem;
//             cin >> first_rem;
//             first_rem %= n;
//             rem[i] = first_rem;

//             for(int j = 1; j < m; ++j){
//                 int val;
//                 cin >> val;
//                 if(val % n != first_rem) {
//                     possible = false;
//                     break;
//                 }
//             }
//         }

//         if(possible){
//             vector<bool> used(n);
//             for(int i = 0; i < n && possible; ++i){
//                 if(rem[i] < 0 || rem[i] >= n || used[rem[i]]) {
//                     possible = false;
//                     break;
//                 }
//                 used[rem[i]] = true;
//                 perm[rem[i]] = i + 1;
//             }
//         }

//         if(!possible) {
//             cout << "-1\n";
//             // Skip remaining input if not possible
//             if(t) for(int i = possible ? 0 : n-1; i < n; ++i)
//                 for(int j = 0; j < m; ++j)
//                     cin >> m;
//             continue;
//         }

//         for(int i = 0; i < n; ++i)
//             cout << perm[i] << " \n"[i == n-1];
//     }
//     return 0;
// }



// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); 
//     int t;
//     cin >> t;
//     while (t--) {
//         int a1, a2, a4, a5;
//         cin >> a1 >> a2 >> a4 >> a5;
//         int maxFib = 0;
//         for (int a3 = -99; a3 <= 300; a3++) {
//             int fib = 0;
//             if (a3 == a1 + a2) fib++;
//             if (a4 == a2 + a3) fib++;
//             if (a5 == a3 + a4) fib++;
//             maxFib = max(maxFib, fib);
//         }
//         cout << maxFib << "\n";
//     }
//     return 0;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); 
//     string a, b;
//     cin >> a >> b;
//     for (char &c : a) c = tolower(c);
//     for (char &c : b) c = tolower(c);
//     if (a < b) cout << "-1";
//     else if (a > b) cout << "1"; 
//     else cout << "0";
// }

// } Driver Code Ends
//User function Template for C++
// class Solution{
//   public:
//     string compareNM(int n, int m){
//         // code here
//         if (n>m) cout<< "greater";
//         else if (n==m) cout<< "equal";
//         else cout<<"lesser";
//     }
// };
// //{ Driver Code Starts.
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n,m ; cin>>n>>m;
//         Solution obj;
//         cout<<obj.compareNM(n,m)<<"\n";   
// cout << "~" << "\n";
// }
//     return 0;
// }
// // } Driver Code Ends
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >>t;
//     while (t--){
//         int n, a, b;
//         cin >> n >>a >>b;
//         if (abs(a - b) % 2 == 1) cout << "NO\n";
//         else cout << "YES\n";
//     }
//     return 0;
// }

// int main() {
//     int n;
//     cin >>n;
//     int arr[n];
//     for (int i=0; i<n; i++) cin>>arr[i];
    //     int hash[13]={0};
//     for (int i=0; i<n; i++){
//         hash[arr[i]]+=1;
//     }
//     int q;
//     cin>>q;
//     while (q--) {
//         int no;
//         cin>> no;
//         cout <<hash[no] <<endl;
//     }
//     return 0;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); 
//     int t;
//     cin >>t;
//     while (t--){
//         int n;
//         cin >>n;
//         vector <int> a(n,0), b(n,0);
//         for (int i=0; i<n; i++) cin>>a[i];
//         for (int i=0; i<n; i++) cin>>b[i];       
//         int dsmall, dbig;
//         dsmall=INT_MAX;
//         dbig=INT_MAX;
//         for (int i=0; i<n; i++){
//             int diff= a[i]-b[i];
//             if (diff<dsmall){
//                 dbig = dsmall;
//                 dsmall = diff;
//             }else if (diff < dbig) dbig = diff;
//         }
//         if (dsmall+dbig>=0) cout<<"YES"<<"\n";
//         else cout<< "NO"<<"\n";
//     }
// }