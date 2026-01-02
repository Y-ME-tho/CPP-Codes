#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (auto &x : v)
            cin >> x;

        map<long long, int> m;
        for (auto x : v)
        {
            m[x % k]++;
        }

        long long bestRem = -1;
        int bestFreq = 0;

        for (auto [rem, freq] : m)
        {
            if (rem == 0)
                continue;
            if (freq > bestFreq)
            {
                bestFreq = freq;
                bestRem = rem;
            }
        }

        if (bestFreq == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            long long ans = (long long)(bestFreq - 1) * k + (k - bestRem) + 1;
            cout << ans << '\n';
        }
    }
}