#include <bits/stdc++.h>
using namespace std;

long long count_good(long long n) {
    if (n == 0) return 0;
    long long bad = 0;
    bad += n/2 + n/3 + n/5 + n/7;
    bad -= n/6 + n/10 + n/14 + n/15 + n/21 + n/35;
    bad += n/30 + n/42 + n/70 + n/105;
    bad -= n/210;
    return n - bad;
}

int main(){
    int n; cin >> n;
    while (n--){
        long long l, r; cin >> l >> r;
        cout << count_good(r) - count_good(l - 1) << endl;
    }
}