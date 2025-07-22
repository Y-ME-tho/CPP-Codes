#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (auto &x : v) cin >> x;

        vector<int> hsh(n + 1, 0);
        for (int i = 0; i < n; i++) {
            hsh[i + 1] = hsh[i] + v[i];
        }

        int no = 0;
        int i = 0;

        while (i + k <= n) {
            if (hsh[i + k] - hsh[i] == 0) {
                no++;
                i += k + 1;
            } else {
                i++;
            }
        }

        cout << no <<endl;
    }
}
