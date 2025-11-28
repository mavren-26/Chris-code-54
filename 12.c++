#include <iostream>
#include <vector>
using namespace std;

class HashLP {
public:
    int n;
    vector<int> table;

    HashLP(int size) {
        n = size;
        table.assign(n, -1);
    }

    void insertKey(int key) {
        int idx = key % n;
        int start = idx;

        while (table[idx] != -1 && table[idx] != -2) {
            idx = (idx + 1) % n;
            if (idx == start) return;
        }
        table[idx] = key;
    }

    int searchKey(int key) {
        int idx = key % n;
        int start = idx;

        while (table[idx] != -1) {
            if (table[idx] == key) return idx;
            idx = (idx + 1) % n;
            if (idx == start) break;
        }
        return -1;
    }

    void deleteKey(int key) {
        int pos = searchKey(key);
        if (pos != -1) table[pos] = -2;
    }
};
