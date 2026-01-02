#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n+1], pf[n+1];
    arr[0]=0;
    for(int i=1; i<=n;i++){
        cin>>arr[i];
        pf[i]=arr[i];
    }
    for (int i=1;i<=n;i++){
        pf[i]=pf[i-1]+pf[i];
    }
    for (int i=1;i<=n-k+1;i++){
        arr[i]=pf[i+k-1]-pf[i-1];
    }
    int min=1;
    for (int i=1; i<=n-k+1;i++){
        if(arr[i]<arr[min]) min=i;
    }
    cout<<min<<endl;
}