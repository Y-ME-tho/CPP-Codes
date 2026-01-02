#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> P, E;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        P.insert(s);
    }
    for(int i = 0; i < m; ++i){
        cin >> s;
        E.insert(s);
    }

    int common = 0;
    for (auto& w : P)
        if (E.count(w))
            ++common;

    if (common % 2)
        cout << (n >= m ? "YES\n" : "NO\n");
    else
        cout << (n >  m ? "YES\n" : "NO\n");

    return 0;
}
