#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());
        bool flag = true;
        string s = "";
        for(int i = 0; i < n; i++){
            if(i == 0){
                s.append(v[0].first, 'R');
                s.append(v[0].second, 'U');
            } else {
                if(v[i].second < v[i-1].second){
                    cout << "NO\n";
                    flag = false;
                    break;
                }
                s.append(v[i].first - v[i-1].first, 'R');
                s.append(v[i].second - v[i-1].second, 'U');
            }
        }
        if(flag){
            cout << "YES\n" << s << "\n";
        }
    }
    return 0;
}
