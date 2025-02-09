// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         int n=s.size();
//         s[n-2] = 'i';
//         s.pop_back();
//         cout<<s<<"\n";
//     }
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         int c=0;
//         for (int i =0; i<s.size()-1; i++){
//             if (s[i]==s[i+1]) c+=1;
//         }
//         if (c!=0) cout<<"1"<<"\n";
//         else cout<<s.size()<<"\n";
//     }
// }


// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//         int n, m, c;
//         cin >> n >> m;
//         vector<int> a(n);
//         for(auto &x : a) cin >> x;
//         int b; cin >> b;
//         c = INT_MIN;
//         bool possible = true;
//         for (int i = 0; i < n; i++){
//             long long L = min(a[i], b - a[i]);
//             long long R = max(a[i], b - a[i]);
//             if(L >= c) c = L;
//             else if(R >= c) c = R;
//             else{
//                 possible = false;
//                 break;
//             }
//         }
//         cout << (possible ? "YES" : "NO") << "\n";
//     }
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--){
//         int n, m;
//         cin >> n >> m;
//         vector<int> a(n), b(m);
//         for(auto &x : a) cin >> x;
//         for(auto &x : b) cin >> x;
//         sort(b.begin(), b.end());
//         long long c = INT_MIN;
//         bool possible = true;
//         for (int i = 0; i < n; i++){
//             long long cand = INT_MAX;
//             if(a[i] >= c) cand = min(cand, (long long)a[i]);
//             long long req = c + a[i];
//             auto it = lower_bound(b.begin(), b.end(), req);
//             if(it != b.end()) cand = min(cand, (long long)(*it) - a[i]);
//             if(cand == INT_MAX){
//                 possible = false;
//                 break;
//             }
//             c = cand;
//         }
//         cout << (possible ? "YES" : "NO") << "\n";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t; cin >> t;
//     while(t--){
//         int n, m; 
//         cin >> n >> m;
//         vector<long long> t(n), inner(n);
//         for (int i = 0; i < n; i++){
//             long long sum = 0, prefix = 0;
//             inner[i] = 0;
//             for (int j = 0; j < m; j++){
//                 int x; 
//                 cin >> x;
//                 sum += x;
//                 prefix += x;
//                 inner[i] += prefix;
//             }
//             t[i] = sum;
//         }
//         vector<int> idx(n);
//         iota(idx.begin(), idx.end(), 0);
//         sort(idx.begin(), idx.end(), [&](int i, int j){ return t[i] > t[j]; });
//         long long ans = 0, add = 0;
//         for (int i = 0; i < n; i++){
//             int k = idx[i];
//             ans += inner[k] + add * m;
//             add += t[k];
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }
