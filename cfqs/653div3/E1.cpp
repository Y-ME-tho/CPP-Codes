#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n + 1, 0);
        for (ll i = 1; i <= n; i++) cin >> v[i];
        sort(v.begin() + 1, v.end());

        if (k == 1) {
            ll min_gap = LLONG_MAX;
            for (ll i = 2; i <= n; i++)
                min_gap = min(min_gap, v[i] - v[i - 1]);
            cout << min(v[1], min_gap) << '\n';
        }
        else if (k == 2) {
            ll ans = v[1];
            for (ll i = 1; i <= n; ++i) {
                for (ll j = i + 1; j <= n; ++j) {
                    ll g = v[j] - v[i];
                    auto it = lower_bound(v.begin() + 1, v.end(), g);
                    if (it != v.end()) ans = min(ans, *it - g);
                    if (it != v.begin() + 1) ans = min(ans, g - *(it - 1));
                    if (ans == 0) break;
                }
                if (ans == 0) break;
            }
            cout << ans << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}
