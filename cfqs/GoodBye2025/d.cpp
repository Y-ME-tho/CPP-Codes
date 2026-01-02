#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });

        vector<pair<int,int>> ops;

        if (m == n) {
            cout << -1 << "\n";
            continue;
        }

        if (m >= 2) {
            if (2LL * m > n) {
                cout << -1 << "\n";
                continue;
            }

            int bsz = n - m;
            vector<int> B(p.begin(), p.begin() + bsz);
            vector<int> S(p.begin() + bsz, p.end());

            vector<int> endpoints(m);

            for (int i = 0; i < m; i++) {
                int prev = B[i];
                for (int j = i + m; j < bsz; j += m) {
                    ops.push_back({prev + 1, B[j] + 1});
                    prev = B[j];
                }
                endpoints[i] = prev;
            }

            for (int i = 0; i < m; i++) {
                ops.push_back({S[i] + 1, endpoints[i] + 1});
            }

            cout << (int)ops.size() << "\n";
            for (auto &e : ops) cout << e.first << " " << e.second << "\n";
            continue;
        }

        if (m == 1) {
            for (int i = 0; i < n - 2; i++) {
                ops.push_back({p[i] + 1, p[i + 1] + 1});
            }
            ops.push_back({p[n - 1] + 1, p[n - 2] + 1});

            cout << (int)ops.size() << "\n";
            for (auto &e : ops) cout << e.first << " " << e.second << "\n";
            continue;
        }

        long long total = 0;
        for (auto v : a) total += v;
        long long mx = *max_element(a.begin(), a.end());

        if (mx > total - mx || n == 2) {
            cout << -1 << "\n";
            continue;
        }

        int Sidx = p[n - 1];
        int Tidx = p[n - 2];
        long long need = a[Sidx] - a[Tidx];

        long long acc = 0;
        int k = 0;
        while (k <= n - 3 && acc < need) {
            ops.push_back({p[k] + 1, Sidx + 1});
            acc += a[p[k]];
            k++;
        }

        if (k <= n - 3) {
            for (int i = k; i < n - 3; i++) {
                ops.push_back({p[i] + 1, p[i + 1] + 1});
            }
            ops.push_back({p[n - 3] + 1, Tidx + 1});
        }

        ops.push_back({Tidx + 1, Sidx + 1});

        cout << (int)ops.size() << "\n";
        for (auto &e : ops) cout << e.first << " " << e.second << "\n";
    }
}
