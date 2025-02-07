// 1
// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<long long> a(n), b(n);
//         for(auto &x : a) cin >> x;
//         for(auto &x : b) cin >> x;
//         set<long long> sA(a.begin(), a.end()), sB(b.begin(), b.end());
//         int dA = sA.size(), dB = sB.size();
//         if((dA == 1 && dB < 3) || (dB == 1 && dA < 3))
//             cout << "NO\n";
//         else
//             cout << "YES\n";
//     }
//     return 0;
// }

// 2
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);cin.tie(nullptr);
//  int t;cin>>t;while(t--){
//   int n,k;cin>>n>>k; vector<long long> a(n);
//   for(int i=0;i<n;i++) cin>>a[i];
//   if(n>k){
//     bool flag=false;
//     for(int j=1;j<=n-k+1;j++){
//       if(a[j]!=1){ flag=true; break; }
//     }
//     cout<<(flag?1:2)<<"\n";
//   } else {
//     int m=k/2, ans=m+1;
//     for(int i=1;i<=m;i++){
//       if(a[2*i-1]!=i){ ans=i; break; }
//     }
//     cout<<ans<<"\n";
//   }
//  }
//  return 0;
// }

// 4
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <tuple>
// #include <cmath>
// using namespace std;
 
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while(t--){
//         int n, s1, s2;
//         cin >> n >> s1 >> s2;
//         s1--; s2--;
//         vector<vector<int>> graph1(n), graph2(n);
//         int m1;
//         cin >> m1;
//         for (int i = 0; i < m1; i++){
//             int a, b;
//             cin >> a >> b;
//             a--; b--;
//             graph1[a].push_back(b);
//             graph1[b].push_back(a);
//         }
//         int m2;
//         cin >> m2;
//         for (int i = 0; i < m2; i++){
//             int a, b;
//             cin >> a >> b;
//             a--; b--;
//             graph2[a].push_back(b);
//             graph2[b].push_back(a);
//         }
        
//         vector<bool> good(n, false);
//         for (int v = 0; v < n; v++){
//             vector<bool> mark(n, false);
//             for (int nei : graph1[v])
//                 mark[nei] = true;
//             for (int nei : graph2[v]){
//                 if(mark[nei]){
//                     good[v] = true;
//                     break;
//                 }
//             }
//         }
        
//         auto idx = [&](int a, int b) -> int {
//             return a * n + b;
//         };
//         const long long INF = 1e18;
//         int totalStates = n * n;
//         vector<long long> dist(totalStates, INF);
//         typedef tuple<long long, int, int> State;
//         priority_queue<State, vector<State>, greater<State>> pq;
        
//         int start = idx(s1, s2);
//         dist[start] = 0;
//         pq.push(make_tuple(0LL, s1, s2));
        
//         long long ans = -1;
//         while(!pq.empty()){
//             State cur = pq.top();
//             pq.pop();
//             long long d = std::get<0>(cur);
//             int v1 = std::get<1>(cur);
//             int v2 = std::get<2>(cur);
//             if(d != dist[idx(v1, v2)])
//                 continue;
//             if(v1 == v2 && good[v1]){
//                 ans = d;
//                 break;
//             }
//             for (int u1 : graph1[v1]){
//                 for (int u2 : graph2[v2]){
//                     int nextID = idx(u1, u2);
//                     long long nd = d + abs(u1 - u2);
//                     if(nd < dist[nextID]){
//                         dist[nextID] = nd;
//                         pq.push(make_tuple(nd, u1, u2));
//                     }
//                 }
//             }
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }

// 3
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<vector<long long>> a(n, vector<long long>(n));
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 cin >> a[i][j];
                
//         vector<int> suff(n, 0);
//         for (int i = 0; i < n; i++){
//             int cnt = 0;
//             for (int j = n - 1; j >= 0; j--){
//                 if(a[i][j] == 1)
//                     cnt++;
//                 else
//                     break;
//             }
//             suff[i] = cnt;
//         }
        
//         sort(suff.begin(), suff.end());
//         int assign = 0;
//         for (int i = 0; i < n; i++){
//             if (suff[i] >= assign + 1)
//                 assign++;
//         }
//         cout << assign + 1 << "\n";
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<vector<long long>> ar(n, vector<long long>(n));
//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < n; j++){
//                 cin >> ar[i][j];
//             }
//         }
        
//         vector<int> tr(n, 0);
//         for (int i = 0; i < n; i++){
//             int count = 0;
//             for (int j = n - 1; j >= 0; j--){
//                 if(ar[i][j] == 1)
//                     count++;
//                 else
//                     break;
//             }
//             tr[i] = count;
//         }
        
//         sort(tr.begin(), tr.end());
//         int assigned = 0;
//         for (int i = 0; i < n; i++){
//             if(tr[i] >= assigned + 1)
//                 assigned++;
//         }
//         cout << assigned + 1 << "\n";
//     }
//     return 0;
// }




