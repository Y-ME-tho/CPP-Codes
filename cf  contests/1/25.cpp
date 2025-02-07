// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve1();
//     return 0;
// }

// bool canReach(vector<int>& scarecrows, int k, int l, int time) {
//     for (int a : scarecrows) {
//         if (a + time + k < l) {
//             return false;
//         }
//     }
//     return true;
// }

// void solve() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k, l;
//         cin >> n >> k >> l;
        
//         vector<int> scarecrows(n);
//         for (int i = 0; i < n; i++) {
//             cin >> scarecrows[i];
//         }
        
//         int left = 0, right = l, answer = 0;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (canReach(scarecrows, k, l, mid)) {
//                 answer = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }
        
//         cout << 2 * answer << '\n';
//     }
// }

// void solve1(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >>t;
//     while(t--){
//         int n, l, r, k, s = 0, no = 0;
//         cin>> n >>l >>r >>k;
//         vector <int> a(n);
//         for (int i=0; i<n; i++) cin>>a[i];
//         for (auto it: a){
//             if (it<r && it>n){
//                 if (s>=k){
//                     s+=it;
//                     no+=1;
//                 } else {
//                     cout<<k<<"\n";
//                     break;
//                 }
//             }
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >>t;
//     while(t--){
//         vector<string> a;
//         for (int i=0; i<3; i++){
//            cin >>a[i] ;
//         }
//         for (int i = 0; i < 3; i++) {
//             size_t j = a[i].find('?');
//             set<char> letters = {'A', 'B', 'C'};
//             if (j != string::npos) {
//                 for (int i=0; i<3; i++){
//                     if (int k != i){
//                         letters.erase(a[k]);
//                     }
//                 }                
//     }    
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >>t;
//     while(t--){
//         int a, b, c;
//         cin >>a >>b >>c;
//         if (a==b) cout<< c <<"\n";
//         else if (a==c) cout<<b <<"\n";
//         else cout<<a <<"\n";
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
//         long long sum = accumulate(a.begin(), a.end(), 0);
//         double sqrtSum = sqrt(sum);
//         if (sqrtSum == floor(sqrtSum)) cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
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



// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> c(n);
//         for (int i = 0; i < n; i++) {
//             cin >> c[i];
//         }

//         vector<pair<long long, int>> visits;
//         for (int i = 0; i < n; i++) {
//             visits.push_back({c[i], i + 1});
//         }
//         sort (visits.begin(), visits.end());

//         long long total_time = 0;
//         vector<int> coordinates(n + 1);
//         coordinates[0] = 0;

//         for (int i = 0; i < n; i++) {
//             coordinates[visits[i].second] = i + 1;
//             total_time += 2LL * visits[i].first * (i + 1);
//         }

//         cout << total_time << '\n';
//         for (int i = 0; i <= n; i++) {
//             cout << coordinates[i] << ' ';
//         }
//         cout << '\n';
//     }
// }





#include<bits/stdc++.h>
using namespace std;

long long sum_digits(long long x){
    long long s=0;
    while(x>0){
        s += x%10;
        x /=10;
    }
    return s;
}

int main(){
    long long n;
    cin>>n;
    long long start = max (1LL, n - 81);
    vector <long long> res;
    for(long long x = start; x <n; x++) {
        if(x + sum_digits(x) ==n){
            res.push_back(x);
        }
    }
    if(res.empty()) cout<<0;
    else{
        cout<< res.size() <<endl;
        for(auto x: res) cout<<x<<endl;
    }
}




