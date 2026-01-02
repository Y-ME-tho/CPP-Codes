#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) ans += (a[i] - b[i]);
        }
        cout << ans+1 << '\n';
    }
}
