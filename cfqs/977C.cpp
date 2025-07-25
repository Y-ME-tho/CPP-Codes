#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, c;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // vector<int> a(n);
    // a = v;
    // sort(v.begin(), v.end());
    // if (k==0) cout<<((v[0]-1)>=1?v[0]-1:-1)<<endl;
    // else if ((c=count(v.begin(), v.end(), v[k-1]))==1) cout<<v[k-1]<<endl;
    // else cout<<-1<<endl;
    sort(v.begin(), v.end());
    if (k == 0)
    {
        cout << (v[0] > 1 ? v[0] - 1 : -1) << "\n";
    }
    else if (k == n)
    {
        cout << v[n - 1] << "\n";
    }
    else if (v[k - 1] < v[k])
    {
        cout << v[k - 1] << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}