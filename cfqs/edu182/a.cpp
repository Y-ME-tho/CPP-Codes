#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            v[i] = v[i - 1] + x;
        }

        if (v[n] % 3 != 0) {
            cout << 0 << ' ' << 0 << '\n';
        } else {
            cout << 1 << ' ' << n-1 << '\n';
        }
    }
}
