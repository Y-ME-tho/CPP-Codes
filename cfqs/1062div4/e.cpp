#include <bits/stdc++.h>
using namespace std;

bool canD(long long D, const vector<long long>& a, int k, long long x) {
    if (D == 0) return true;

    vector<pair<long long, long long>> iv;
    iv.reserve(a.size());

    for (long long v : a) {
        long long L = max(0LL, v - (D - 1));
        long long R = min(x,    v + (D - 1));
        if (L <= R) iv.push_back({L, R});
    }

    sort(iv.begin(), iv.end());

    long long cur = 0;
    long long cnt = 0;

    for (auto pr : iv) {
        long long L = pr.first;
        long long R = pr.second;

        if (cur < L) cnt += (L - cur);
        if (cnt >= k) return true;

        cur = max(cur, R + 1);
        if (cur > x) break;
    }

    if (cur <= x) cnt += (x - cur + 1);

    return cnt >= k;
}

vector<long long> build(long long D, const vector<long long>& a, int k, long long x) {
    vector<long long> res;
    res.reserve(k);

    if (D == 0) {
        for (long long p = 0; (int)res.size() < k && p <= x; ++p) res.push_back(p);
        return res;
    }

    vector<pair<long long, long long>> iv;
    iv.reserve(a.size());

    for (long long v : a) {
        long long L = max(0LL, v - (D - 1));
        long long R = min(x,    v + (D - 1));
        if (L <= R) iv.push_back({L, R});
    }

    sort(iv.begin(), iv.end());

    long long cur = 0;

    for (auto pr : iv) {
        long long L = pr.first;
        long long R = pr.second;

        while (cur < L && (int)res.size() < k) {
            res.push_back(cur);
            ++cur;
        }

        cur = max(cur, R + 1);

        if ((int)res.size() >= k || cur > x) break;
    }

    while ((int)res.size() < k && cur <= x) {
        res.push_back(cur);
        ++cur;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long x;

        cin >> n >> k >> x;

        vector<long long> a(n);
        for (auto &v : a) cin >> v;
        sort(a.begin(), a.end());

        long long lo = 0;
        long long hi = x;
        long long ans = 0;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            if (canD(mid, a, k, x)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        auto pos = build(ans, a, k, x);

        for (int i = 0; i < k; i++) {
            cout << pos[i] << (i + 1 < k ? ' ' : '\n');
        }
    }
}
