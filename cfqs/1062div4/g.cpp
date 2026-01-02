#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<long long> a(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        long long sumC = 0;
        for (int i = 0; i < n; ++i){ cin >> c[i]; sumC += c[i]; }

        vector<long long> dp(n, 0);
        long long best = 0;
        for (int i = 0; i < n; ++i){
            long long bestPrev = 0;
            for (int j = 0; j < i; ++j)
                if (a[j] <= a[i]) bestPrev = max(bestPrev, dp[j]);
            dp[i] = c[i] + bestPrev;
            best = max(best, dp[i]);
        }

        cout << (sumC - best) << '\n';
    }
    return 0;
}
