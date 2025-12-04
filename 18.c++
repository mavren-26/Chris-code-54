// double_hash_table.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Entry {
    int key;
    int state; // 0 empty, 1 occ, 2 deleted
    Entry(): key(0), state(0) {}
};

class DoubleHashTable {
    int m;
    vector<Entry> table;
public:
    DoubleHashTable(int m_): m(m_), table(m_) {}

    int h1(int k) const { int v = k % m; if (v<0) v += m; return v; }
    int h2(int k) const { int v = abs(k) % (m - 1); return 1 + v; }

    bool search(int k) const {
        int a = h1(k), b = h2(k);
        for (int i = 0; i < m; ++i) {
            int idx = (a + i * b) % m;
            if (table[idx].state == 0) return false;
            if (table[idx].state == 1 && table[idx].key == k) return true;
        }
        return false;
    }

    void insert(int k) {
        if (search(k)) return;
        int a = h1(k), b = h2(k);
        int first_del = -1;
        for (int i = 0; i < m; ++i) {
            int idx = (a + i * b) % m;
            if (table[idx].state == 0) {
                if (first_del != -1) idx = first_del;
                table[idx].key = k; table[idx].state = 1;
                return;
            }
            if (table[idx].state == 2 && first_del == -1) first_del = idx;
        }
        // full (no rehash implemented)
        if (first_del != -1) {
            table[first_del].key = k; table[first_del].state = 1;
        }
    }

    void remove(int k) {
        int a = h1(k), b = h2(k);
        for (int i = 0; i < m; ++i) {
            int idx = (a + i * b) % m;
            if (table[idx].state == 0) return;
            if (table[idx].state == 1 && table[idx].key == k) {
                table[idx].state = 2;
                return;
            }
        }
    }

    void print() const {
        for (int i = 0; i < m; ++i) {
            if (table[i].state == 1) cout << table[i].key;
            else cout << "EMPTY";
            if (i+1 < m) cout << " ";
        }
        cout << "\n";
    }
};

// Driver for Problem 1: read commands from stdin
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    if (!(cin >> m >> n)) return 0;
    DoubleHashTable ht(m);
    for (int i = 0; i < n; ++i) {
        string cmd; cin >> cmd;
        if (cmd == "INSERT") {
            int x; cin >> x; ht.insert(x);
        } else if (cmd == "DELETE") {
            int x; cin >> x; ht.remove(x);
        } else if (cmd == "SEARCH") {
            int x; cin >> x; cout << (ht.search(x) ? "YES\n" : "NO\n");
        } else if (cmd == "PRINT") {
            ht.print();
        }
    }
    return 0;
}
