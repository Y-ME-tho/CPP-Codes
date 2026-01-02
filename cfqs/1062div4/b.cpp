#include <bits/stdc++.h>
using namespace std;
int arr1[26];
int arr2[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        string s,t; cin>>s>>t;
        fill(begin(arr1), end(arr1), 0);
        fill(begin(arr2), end(arr2), 0);
        for (int i=0; i<n; i++) arr1[s[i]-'a']++;
        for (int i=0; i<n; i++) arr2[t[i]-'a']++;
        bool flag =true;
        for (int i=0; i<26; i++){
            if (arr1[i]!=arr2[i]){
            flag = false;
            cout<<"NO"<<endl;
            break;
            }
        }
        if (flag==true) cout<<"YES"<<endl;

    }
}