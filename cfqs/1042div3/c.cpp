#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &v1, vector<long long> &v2, long long k){
    unordered_map<long long,long long> A, B;
    for (auto &x : v1) A[x % k]++;
    for (auto &x : v2) B[x % k]++;
    unordered_set<long long> seen;
    vector<long long> keys; keys.reserve(A.size() + B.size());
    for (auto &p : A) keys.push_back(p.first);
    for (auto &p : B) keys.push_back(p.first);
    for (auto r : keys) {
        if (seen.count(r)) continue;
        long long s = (k - (r % k)) % k;
        if (r == s) {
            if (A[r] != B[r]) return false;
            seen.insert(r);
        } else {
            if (A[r] + A[s] != B[r] + B[s]) return false;
            seen.insert(r);
            seen.insert(s);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        long long n, k; 
        cin >> n >> k;
        vector<long long> v1(n), v2(n);
        for (auto &x : v1) cin >> x;
        for (auto &x : v2) cin >> x;
        cout << (check(v1, v2, k) ? "YES\n" : "NO\n");
    }
    return 0;
}
