#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        int i = __builtin_ctz(x);
        if ((x & (x - 1)) != 0) {
            cout << (1 << i) << "\n";
        } else {
            int j = __builtin_ctz(~x);
            cout << ((1 << i) | (1 << j)) << "\n";
        }
    }
}
