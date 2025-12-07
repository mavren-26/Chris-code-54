// Falling Tombstones - C++ solution (no bits/stdc++.h)
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) {
        // example
        s = "1101101";
        int T = 1;
        // run example below
        int n = (int)s.size();
        vector<bool> standing(n);
        for (int i = 0; i < n; ++i) standing[i] = (s[i] == '1');
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i-1 >= 0 && standing[i-1]) cnt[i]++;
            if (i+1 < n && standing[i+1]) cnt[i]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (standing[i] && cnt[i] < T) q.push(i);
        int days = 0;
        while (!q.empty()) {
            days++;
            int sz = q.size();
            // to achieve simultaneous fall we process current size
            // but new failing ones may be added; we collect them in a temp queue
            queue<int> temp;
            while (!q.empty()) {
                int i = q.front(); q.pop();
                if (!standing[i]) continue;
                standing[i] = false;
                for (int nb : {i-1, i+1}) {
                    if (nb >= 0 && nb < n && standing[nb]) {
                        cnt[nb]--;
                        if (cnt[nb] < T) temp.push(nb);
                    }
                }
            }
            swap(q, temp);
        }
        string final;
        for (bool b : standing) final.push_back(b ? '1' : '0');
        cout << final << "\n" << days << "\n";
        return 0;
    }
    int T;
    cin >> T;
    int n = (int)s.size();
    vector<bool> standing(n);
    for (int i = 0; i < n; ++i) standing[i] = (s[i] == '1');
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i-1 >= 0 && standing[i-1]) cnt[i]++;
        if (i+1 < n && standing[i+1]) cnt[i]++;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (standing[i] && cnt[i] < T) q.push(i);
    int days = 0;
    while (!q.empty()) {
        days++;
        queue<int> temp;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (!standing[i]) continue;
            standing[i] = false;
            for (int nb : {i-1, i+1}) {
                if (nb >= 0 && nb < n && standing[nb]) {
                    cnt[nb]--;
                    if (cnt[nb] < T) temp.push(nb);
                }
            }
        }
        swap(q, temp);
    }
    for (bool b : standing) cout << (b ? '1' : '0');
    cout << "\n" << days << "\n";
    return 0;
}
