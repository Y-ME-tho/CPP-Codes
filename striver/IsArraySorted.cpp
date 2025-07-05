//check if an array is sorted
#include <bits/stdc++.h>
using namespace std;

bool arrsorted(int arr[], int n){
    for (int i=0; i<n-1; i++){
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        cout<< arrsorted(a, n);
    }
}