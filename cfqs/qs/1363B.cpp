#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (s[i] == '1');

    int total1 = pre[n];
    int ans = n;

    for (int i = 0; i <= n; i++)
    {
        int flipA = pre[i] + ((n - i) - (total1 - pre[i]));

        int flipB = i - pre[i] + (total1 - pre[i]);

        ans = min({ans, flipA, flipB});
    }

    cout << ans << "\n";
}
