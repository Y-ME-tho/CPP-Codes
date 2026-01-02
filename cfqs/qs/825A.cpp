#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int n; cin>>n;
//     string s; cin>>s;
//     int k=0, no=0;
//     for (int i=0; i<n; i++){
//         if(s[i]=='1') k+=1;
//         else{
//             if (k>0) no=no*10 + k;
//             else if(k==0 && s[i-1]=='0') no=no*10 + k;
//             k=0;
//         }
//     }
//     // if (k > 0) no = no * 10 + k;
//     cout<<no<<endl;
// }

int main(){
    int n; cin>>n;
    string s; cin>>s;
    int k=0, no=0;
    for (int i=0; i<n; i++){
        if(s[i]=='1') k+=1;
        else{
            if (k>0) {no=no*10 + k; no=no*10;}
            else if(k==0) no=no*10 + k;
            k=0;
        }
    }
    if (k > 0) no = no * 10 + k;
    cout<<no<<endl;
}

