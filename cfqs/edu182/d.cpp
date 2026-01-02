#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long t; cin>>t;
    while (t--) {
        long long n; long long y;
        cin >> n >> y;
        vector<long long> c(n);
        long long C = 0;
        for (long long i = 0; i < n; ++i) {
            cin >> c[i];
            C = max(C, c[i]);
        }

        vector<long long> f(C + 2, 0), pref(C + 2, 0);
        for (long long v : c) ++f[v];
        for (long long i = 1; i <= C; ++i) pref[i] = pref[i - 1] + f[i];

        auto range_cnt = [&](long long L, long long R) -> long long {
            if (L > R) return 0;
            if (R > C) R = C;
            if (L < 1) L = 1;
            return pref[(long long)R] - pref[(long long)(L - 1)];
        };

        long long best = LLONG_MIN;

        for (long long x = 2; x <= C + 1; ++x) {
            long long S = 0;
            long long M = 0;

            for (long long v = 1;; ++v) {
                long long L = (v - 1) * x + 1;
                if (L > C) break;
                long long R = min(1LL * v * x, 1LL * C);

                long long cnt = range_cnt(L, R);
                if (!cnt) continue;

                S += v * cnt;
                if (v <= C) M += min(cnt, f[(long long)v]);
            }

            long long printed = (long long)n - M;
            long long revenue = S - y * printed;
            if (revenue > best) best = revenue;
        }

        cout << best << "\n";
    }
}
