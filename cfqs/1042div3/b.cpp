#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            long long x;
            if (i & 1) {
                x = -1;
            } else if (i == n) {
                x = 2;
            } else {
                x = 3;
            }
            if (i > 1) cout << ' ';
            cout << x;
        }
        cout << '\n';
    }
}
