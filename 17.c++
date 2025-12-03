#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StringHashTable {
public:
    int size;
    vector<vector<string>> table;

    StringHashTable(int s = 10) {
        size = s;
        table.resize(size);
    }

    int hashFunc(const string &s) {
        int sum = 0;
        for (char c : s) sum += (int)c;
        return sum % size;
    }

    void insertKey(const string &key) {
        int idx = hashFunc(key);
        for (auto &x : table[idx]) if (x == key) return;
        table[idx].push_back(key);
    }

    bool searchKey(const string &key) {
        int idx = hashFunc(key);
        for (auto &x : table[idx])
            if (x == key) return true;
        return false;
    }

    vector<string> getChain(const string &key) {
        return table[hashFunc(key)];
    }
};
