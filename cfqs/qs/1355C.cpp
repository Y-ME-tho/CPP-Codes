#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long int arr[N];

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for (int x=a; x<=b; x++){
        arr[x+b]++;
        arr[x+c+1]--;
    }
    for (int i=1; i<=b+c; i++){
        arr[i]= arr[i-1]+arr[i];
    }
    for (int i=1; i<=b+c; i++){
        arr[i]= arr[i-1]+arr[i];
    }

    long long int sum = 0;
    for (int z=c; z<=d; z++){
        if(z>b+c) break;
        sum+=arr[b+c]-arr[z];
    }
    cout<<sum<<endl;
}