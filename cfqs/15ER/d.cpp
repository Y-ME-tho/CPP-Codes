#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    ll time = 0;
    if (d <= k) {
        cout << d * a << endl;
    }
    else if (t + k * a > k * b) {
        cout << k * a + (d - k) * b << endl;
    }
    else {
        ll p = d / k;
        ll rem = d % k;
        time = p * k * a + (p - 1) * t;
        time += min(rem * b, t + rem * a);
        cout << time << endl;
    }
}
