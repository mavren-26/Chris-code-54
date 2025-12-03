#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HashTable {
public:
    int size;
    vector<vector<int>> table;

    HashTable(int s = 10) {
        size = s;
        table.resize(size);
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int idx = hashFunc(key);
        for (int x : table[idx]) if (x == key) return;
        table[idx].push_back(key);
    }

    bool searchKey(int key) {
        int idx = hashFunc(key);
        for (int x : table[idx]) if (x == key) return true;
        return false;
    }

    void removeKey(int key) {
        int idx = hashFunc(key);
        auto &chain = table[idx];
        chain.erase(remove(chain.begin(), chain.end(), key), chain.end());
    }
};
