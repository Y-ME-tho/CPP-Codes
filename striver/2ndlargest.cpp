#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    // sort(a, a+n, greater<int>());
    for (int i=n-2; i>=0; i--){
        if (a[i]!=a[n-1]){
            cout<<a[i];
            break;
        } 
    }
}

int secondlargest(vector<int> &a, int n){
    int largest=a[0];
    int slargest=-1;
    for (int i=1; i<n; i++){
        if (a[i]>largest){
            slargest=largest;
            largest=a[i];
        }else if (a[i]<largest && a[i]>slargest) 
            slargest=a[i];
    }
    return slargest;
}


int secondsmallest(vector<int> &a, int n){
    int smallest =a[0];
    int ssmallest = INT_MAX;
    for (int i=0; i<n; i++){
        if (a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }else if(a[i]<ssmallest) ssmallest=a[i];
    }
    return ssmallest;
}