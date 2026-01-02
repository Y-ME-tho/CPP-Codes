#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long X;
        cin >> n >> X;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        multiset<long long> ms(a.begin(), a.end());
        long long S = 0;
        long long bonus = 0;
        vector<long long> order;

        while (!ms.empty()) {
            long long rem = S % X;
            long long need = (rem == 0 ? X : X - rem);

            auto it_max = prev(ms.end());
            if (*it_max >= need) {
                long long p = *it_max;
                bonus += p;
                S += p;
                order.push_back(p);
                ms.erase(it_max);
            } else {
                auto it_min = ms.begin();
                long long p = *it_min;
                S += p;
                order.push_back(p);
                ms.erase(it_min);
            }
        }

        cout << bonus << "\n";
        for (int i = 0; i < n; i++) {
            cout << order[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}
