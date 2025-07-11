#include <bits/stdc++.h>
using namespace std;
const int N= 2e5+10;
long long arr[N];
set<long long> st;

int main(){
    int n; cin>>n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    st.insert(0);
    long long sum= 0;
    int cnt= 0;
    for (int i=1; i<=n; i++){
        sum+=arr[i];
        if (st.count(sum)){
            cnt++;
            st.clear();
            st.insert(0);
            sum=arr[i];
        }
        st.insert(sum);
    }
    cout<<cnt<<endl;
    return 0;
}
