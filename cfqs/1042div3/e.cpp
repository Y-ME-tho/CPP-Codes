#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        if (a[n-1] != b[n-1]){
            cout << "NO\n"; 
            continue;
        }
        bool ok = true;

        for (int i = n-2; i >= 0; i--){
            if (b[i] == a[i]) continue;
            if (b[i] == (a[i] ^ a[i+1])) continue;
            if (b[i] == (a[i] ^ b[i+1])) continue;
            ok = false; 
            break;
        }
        cout << (ok ? "YES" : "NO");
        cout<<endl;
    }
}
