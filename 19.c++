#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DoubleHashSet {
    int m;
    vector<int> keys;
    vector<int> state; // 0 empty, 1 occ, 2 del
public:
    int distinct = 0;

    DoubleHashSet(int m_) : m(m_), keys(m_), state(m_, 0) {}

    int h1(int k) const { int v = k % m; if (v < 0) v += m; return v; }
    int h2(int k) const { return 1 + (abs(k) % (m - 1)); }

    bool search(int k) {
        int a = h1(k), b = h2(k);
        for (int i = 0; i < m; i++) {
            int idx = (a + i * b) % m;
            if (state[idx] == 0) return false;
            if (state[idx] == 1 && keys[idx] == k) return true;
        }
        return false;
    }

    void insert(int k) {
        if (search(k)) return; // already exists

        int a = h1(k), b = h2(k);
        int firstDel = -1;

        for (int i = 0; i < m; i++) {
            int idx = (a + i * b) % m;

            if (state[idx] == 0) {
                int pos = (firstDel != -1 ? firstDel : idx);
                keys[pos] = k;
                state[pos] = 1;
                distinct++;
                return;
            }
            if (state[idx] == 2 && firstDel == -1) {
                firstDel = idx;
            }
        }

        if (firstDel != -1) {
            keys[firstDel] = k;
            state[firstDel] = 1;
            distinct++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, q;
    cin >> m >> q;

    DoubleHashSet s(m);

    for (int i = 0; i < q; i++) {
        int x; 
        cin >> x;
        s.insert(x);
        cout << s.distinct << "\n";
    }

    return 0;
}
