// #include <bits/stdc++.h>
// using namespace std;

// int k;

// const int INF = 1e9;
// int knapsack(vector<int> wt, vector<int> val, int n, int w){
//     // knapsack has <=wt, here we need exact wt as calorie na, yaad rakh
//     int dp[n+1][w+1];
//     for (int i=0; i<n+1; i++){
//         for (int j=0; j<w+1; j++){
//             if (j==0) dp[i][j]=0;
//             else dp[i][j]= (-INF);
//         }
//     }

//     for (int i=1; i<n+1; i++){
//         for (int j=1; j<w+1; j++){
//             dp[i][j] =  dp[i-1][j];
//             if (wt[i-1]<=j){
//                 if (dp[i-1][j-wt[i-1]]!= -INF){
//                     dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
//                 }
//             }
//         }
//     }
//     int ans = -1;
//     for (int j = 1; j <= w; j++){           
//         if (dp[n][j] == k * j) ans = max(ans, dp[n][j]);
//     }
//     return ans;

// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n; cin>>n>>k;
//     vector<int>a (n,0);
//     vector<int>b (n,0);
//     for (auto &x: a) cin>>x;
//     for (auto &x: b) cin>>x;
//     int ans = knapsack(b, a, n, 100*n);
//     cout<<ans<<endl;


// }



#include <bits/stdc++.h>
using namespace std;

int k;
const int INF = 1e9;

int knapsack(vector<int> wt, vector<int> val, int n, int) {
    vector<int> diff(n);
    long long LOW = 0, HIGH = 0;
    for (int i = 0; i < n; ++i) {
        diff[i] = val[i] - k * wt[i];
        if (diff[i] < 0) LOW += diff[i];
        else HIGH += diff[i];
    }
    int SHIFT = (int)(-LOW);
    int W = (int)(SHIFT + HIGH);

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -INF));
    dp[0][SHIFT] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s <= W; ++s) {
            dp[i][s] = dp[i - 1][s];
            int ps = s - diff[i - 1];
            if (0 <= ps && ps <= W && dp[i - 1][ps] != -INF) {
                dp[i][s] = max(dp[i][s], dp[i - 1][ps] + val[i - 1]);
            }
        }
    }

    int ans = dp[n][SHIFT];
    return (ans > 0 ? ans : -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    cout << knapsack(b, a, n, 100 * n) << "\n";
    return 0;
}
