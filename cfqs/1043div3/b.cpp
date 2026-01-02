#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> ans;

        int len = to_string(n).size();
        long long p = 10;

        for (int k = 1; k <= len; k++) {
            long long d = p + 1;
            if (d > n) break;
            if (n % d == 0) ans.push_back(n / d);
            if (k < len) p *= 10;
        }

        if (ans.empty()) {  
            cout << 0 << "\n";
        } else {
            sort(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (size_t i = 0; i < ans.size(); i++) {
                cout << ans[i] << (i + 1 < ans.size() ? " " : "\n");
            }
        }
    }
}
