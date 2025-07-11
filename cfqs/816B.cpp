#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int arr[N];

int main(){
    int n, k, q;
    cin>>n >>k>>q;
    while (n--){
        int l,r; cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }
    for (int i=1; i<=N; i++){
        arr[i]=arr[i-1]+arr[i];
    }

    for (int i=1;i<=N; i++){
        if (arr[i]>=k) arr[i]=1;
        else arr[i]=0;
    }

    for (int i=1; i<=N; i++){
        arr[i]=arr[i-1]+arr[i];
    }

    while (q--){
        int cnt=0;
        int a,b;
        cin >>a>>b;
        cout<<arr[b]-arr[a-1] << endl;
    }
}