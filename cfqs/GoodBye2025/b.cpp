#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        string s; 
        cin >> s;

        int n = (int)s.size();
        int total = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'u') total++;

        int kept = 0;
        for (int i = 1; i <= n - 2; i++) {
            if (s[i] == 'u') {
                int j = i;
                while (j <= n - 2 && s[j] == 'u') j++;
                int L = j - i;
                kept += (L + 1) / 2;
                i = j - 1;
            }
        }

        cout << total - kept << "\n";
    }
}
