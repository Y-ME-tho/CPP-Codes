#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    long long int arr[n+1], brr[n+1];
    arr[0]=brr[0]=0;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
        brr[i]=arr[i];
    }

    sort(brr+1,brr+n+1);

    for (int i=1; i<=n; i++){
        arr[i]=arr[i-1]+arr[i];
        brr[i]=brr[i-1]+ brr[i];
    }

    int m; cin>>m;
    while (m--){
        int l, r, type;
        cin>>type>>l>>r;
        if(type==1){
            cout<< arr[r]-arr[l-1]<<endl;
        }
        if (type ==2){
            cout<< brr[r]-brr[l-1]<<endl;
        }
    }
}