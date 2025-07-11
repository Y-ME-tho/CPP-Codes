#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long arr[N], pf[N], diff[N];

struct operation {
    int l, r;
    long long d;
};
operation brr[N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> brr[i].l >> brr[i].r >> brr[i].d;
    }

    while (k--) {
        int x, y;
        cin >> x >> y;
        pf[x]++;
        pf[y + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        pf[i] += pf[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        long long times = pf[i];
        int l = brr[i].l;
        int r = brr[i].r;
        long long d = brr[i].d;

        diff[l] += times * d;
        diff[r + 1] -= times * d;
    }

    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        arr[i] += diff[i];
        cout << arr[i] << " ";
    }

    cout << "\n";
    return 0;
}
