#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> g(n + 1);
        vector<int> deg(n + 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            int u,v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);

            deg[u] += 1;
            deg[v] += 1;
        }

        if (n == 2) {
            cout << 0 << '\n';
            continue;
        }

        int leaf = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) {
                leaf += 1;
            }
        }

        int best = 0;
        for (int u = 1; u <= n; ++u) {
            int cnt = 0;
            for (int v : g[u]) {
                if (deg[v] == 1) {
                    cnt += 1;
                }
            }
            if (cnt > best) {
                best = cnt;
            }
        }

        cout << (leaf - best) << '\n';
    }
}
