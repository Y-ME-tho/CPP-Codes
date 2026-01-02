#include <bits/stdc++.h>
using namespace std;
map<long long,long long> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (long long p = 1, i = 0; p <= 1000000000LL; p *= 3, i++)
        m[p] = (i == 0 ? 3 : 3 * p + i * (p / 3));

    int t; cin >> t;
    while (t--) {
        long long n, sum = 0; 
        cin >> n;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            long long cnt = min(2LL, n / it->first);
            n -= cnt * it->first;
            sum += cnt * it->second;
            if (!n) break;
        }
        cout << sum << "\n";
    }
}
