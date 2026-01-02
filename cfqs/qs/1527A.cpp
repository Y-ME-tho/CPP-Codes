#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int t; cin>>t;
//     while (t--){
//         int n; cin>>n; 
//         for (int i=n-1; i; i--){
//             n=n&i;
//             if (n==0){
//                 cout<<i<<endl;
//                 break;
//             }
//         }
//     }
// }

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int msb = 32 - __builtin_clz(n) - 1;
        cout<<((1<<msb)-1)<<endl;
    }
}