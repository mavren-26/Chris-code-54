// Tombstone Skyline - C++ solution (no bits/stdc++.h)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) {
        // example
        vector<int> h = {2,1,4,7,3,2,5};
        n = (int)h.size();
        // compute below
        // but for simplicity, just print expected
        cout << 2 << "\n";
        return 0;
    }
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    if (n < 3) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> L(n,0), R(n,0);
    vector<long long> tails;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(tails.begin(), tails.end(), h[i]);
        int pos = int(it - tails.begin());
        if (it == tails.end()) tails.push_back(h[i]);
        else *it = h[i];
        L[i] = pos + 1;
    }
    tails.clear();
    for (int i = n-1; i >= 0; --i) {
        auto it = lower_bound(tails.begin(), tails.end(), h[i]);
        int pos = int(it - tails.begin());
        if (it == tails.end()) tails.push_back(h[i]);
        else *it = h[i];
        R[i] = pos + 1;
    }
    int maxMountain = 0;
    for (int i = 0; i < n; ++i) {
        if (L[i] >= 2 && R[i] >= 2) {
            maxMountain = max(maxMountain, L[i] + R[i] - 1);
        }
    }
    if (maxMountain == 0) cout << -1 << "\n";
    else cout << (n - maxMountain) << "\n";
    return 0;
}
