#include <bits/stdc++.h>
using namespace std;

int setcreationfromarray(set<int> &st, int a[], int n){//method1
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
}

int StoringUniquesInSet(set<int> &st, int a[]){//method1
    int index;
    index=0;
    for (auto it: st){
        a[index]=it;
        index++;
    }
    for (int i=0; i<st.size(); i++) cout<<a[i]<<"\t";
}

void ifArrayisSorted(int a[], int n){//method2
    int comp=a[0];
    cout<<comp<<"\t";
    for (int i=0; i<n; i++){
        if (a[i]!=comp){
            cout<<a[i]<<"\t";
            comp=a[i];
        }
    }
}

void Using2PointerstoFindUniqueElements(int a[], int n){
    int i=0;
    for (int j=0; j<n; j++ ){
        if (a[j]!=a[i]){
            a[i+1]=a[j];
            i++;
        }
    }
    cout<<i++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> st;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        Using2PointerstoFindUniqueElements(a, n);
        // ifArrayisSorted(a, n);
        // setcreationfromarray(st, a, n);
        // StoringUniquesInSet(st, a);
    }
}


