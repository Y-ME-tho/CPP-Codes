// 1> using sorting techniques its O(nlogn)
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     using namespace std;
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int a[n];
//         for (int i=0; i<n; i++) cin>>a[i];
//         sort(a, a + n);
//         cout<<a[n-1];
//     }
// }


// 2> looping to find
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin>>n;
    int a[n];
    for (int i =0; i<n; i++) cin>>a[i];
    m=a[0];
    for (int i =0; i<n; i++)
        if (a[i]>m) m=a[i];
    cout<<m;
}

