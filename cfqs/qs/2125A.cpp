#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        sort(s.begin(), s.end(), greater<char>());
        // int kf, kn;
        // while((kf=s.find("FFT"))!= string::npos || (kn=s.find("NTT"))!= string::npos){
        //     if (kf!= string::npos) swap(s[kf], s[kf+2]);
        //     if (kn!= string::npos && kf!= kn) swap(s[kn], s[kn+2]);
        // }
        cout<<s<<endl;
    }
}