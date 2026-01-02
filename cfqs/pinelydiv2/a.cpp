#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long R0, X, D;
        int n;
        cin >> R0 >> X >> D >> n;
        string s; cin >> s;

        long long r = R0;
        int ans = 0;

        for (char c : s) {
            if (c == '1') {
                ans++;
                r = r - (long long)D;
                if (r < 0) r = 0;
            } else {
                if (r < X) {
                    ans++;
                    r = r - (long long)D;
                    if (r < 0) r = 0;
                }
            }
        }
        cout << ans <<endl;
    }
}
