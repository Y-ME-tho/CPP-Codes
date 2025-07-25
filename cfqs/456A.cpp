#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int>> v(n);
    for (int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    return a.first > b.first;
    });
    bool flag = false;
    for (int i=0; i<n-1; i++){
        if (v[i].second<v[i+1].second) flag = true;
    }
    if (flag) cout<<"Happy Alex"<<endl;
    else cout<<"Poor Alex"<<endl;
}