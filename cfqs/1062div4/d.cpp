#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);
    return primes;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto primes = sieve(1000000); 
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<long long> v1(n,0);
        for (auto &x:v1) cin>>x;

        long long g = v1[0];
        for (int i = 1; i < n; i++)
            g = __gcd(g, v1[i]);

        long long ans = -1;
        for (auto p : primes) {
            if (__gcd(g, (long long)p) == 1) {
                ans = p;
                break;
            }
        }

        cout << ans << "\n";
    }
}