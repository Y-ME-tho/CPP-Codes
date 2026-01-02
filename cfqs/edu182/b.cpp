#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto &x : v) cin >> x;

        int l1 = n, r1 = -1;
        int l2 = n, r2 = -1;
        int z = 0, zi = -1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                z++; zi = i;
                l2 = min(l2, i);
                r2 = max(r2, i);
            } else {
                sum += v[i];
                if (v[i] != i + 1) {
                    l1 = min(l1, i);
                    r1 = max(r1, i);
                }
            }
        }

        if (r1 == -1) {
            if (z <= 1) cout << 0 << '\n';
            else cout << r2 - l2 + 1 << '\n';
        } else {
            int l = l1, r = r1;
            if (z >= 2) {
                l = min(l, l2);
                r = max(r, r2);
            } else if (z == 1) {
                long long tot = 1LL * n * (n + 1) / 2;
                long long miss = tot - sum;
                if (miss != zi + 1) {
                    l = min(l, zi);
                    r = max(r, zi);
                }
            }
            cout << r - l + 1 << '\n';
        }
    }
}
