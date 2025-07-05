#include <bits/stdc++.h>
using namespace std;

// Checks if, in the given fertility configuration F, no adjacent plots are "stressed."
// That is, for every i, we want |F[i] - F[i+1]| >= T[i].
bool noStress(const vector<int> &F, const vector<int> &T) {
    for (int i = 0; i + 1 < (int)F.size(); i++) {
        if (abs(F[i] - F[i+1]) < T[i]) {
            return false;
        }
    }
    return true;
}

// Given a configuration F, return all possible "next" configurations
// by performing exactly ONE fertilizer application on a contiguous
// block of plots that share the same fertility.
vector<vector<int>> getNextStates(const vector<int> &F, int cap) {
    vector<vector<int>> result;
    int n = (int)F.size();
    
    int start = 0;
    while (start < n) {
        int val = F[start];
        int end = start;
        // Extend end while adjacent plots share the same fertility:
        while (end + 1 < n && F[end + 1] == val) {
            end++;
        }
        // We have a block [start..end] all with value 'val'.
        
        // Only increment if it won't exceed our chosen cap:
        if (val < cap) {
            vector<int> newF = F;
            for (int i = start; i <= end; i++) {
                newF[i] = val + 1;
            }
            result.push_back(newF);
        }
        
        start = end + 1;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // Number of plots
    
    // Read thresholds
    vector<int> T(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> T[i];
    }

    // Quick check: if all T_i = 0, the answer is obviously 0
    bool allZero = true;
    for (int x : T) {
        if (x != 0) { allZero = false; break; }
    }
    if (allZero) {
        cout << 0 << "\n";
        return 0;
    }

    // We'll do a BFS in state-space where a state is the vector [F1,F2,...,Fn].
    // We need an upper bound to avoid infinite state explosion.
    // For the sample, sum of T is 3+4+1+2=10. We'll allow a bit extra, say 12.
    // This is purely to handle small cases. 
    int cap = 0;
    for (int x : T) {
        cap += x;
    }
    cap += 2; // small cushion

    vector<int> start(n, 0); // All plots start at fertility 0.

    // We'll keep a queue for BFS and a map from "encoded state" -> BFS distance
    queue<vector<int>> q;
    unordered_map<string, int> dist;

    // Function to turn a fertility vector into a string (for visited-check).
    auto encode = [&](const vector<int> &Fert) {
        // E.g. "0,0,1,1,0,"
        ostringstream oss;
        for (int val : Fert) {
            oss << val << ",";
        }
        return oss.str();
    };

    // Initialize BFS
    q.push(start);
    dist[encode(start)] = 0;

    // BFS loop
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int steps = dist[encode(cur)];

        // Check if this configuration is stress-free:
        if (noStress(cur, T)) {
            cout << steps << "\n";  // BFS level => minimal operations
            return 0;
        }

        // Generate all next states from cur
        auto nxtList = getNextStates(cur, cap);
        for (auto &nxt : nxtList) {
            string key = encode(nxt);
            if (!dist.count(key)) {
                dist[key] = steps + 1;
                q.push(nxt);
            }
        }
    }

    // If we somehow exhaust the BFS without finding a solution (unlikely here),
    // just print -1 or some indicator. But typically you'll never get here.
    cout << -1 << "\n";
    return 0;
}
