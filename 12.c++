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
//driver code  
int main() {
    HashLP h(7);   // hash table of size 7

    // Insert keys
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(5);
    h.insertKey(15);

    // Search keys
    cout << "Searching 10 -> index " << h.searchKey(10) << endl;
    cout << "Searching 5  -> index " << h.searchKey(5) << endl;
    cout << "Searching 99 -> index " << h.searchKey(99) << endl;

    // Delete a key
    h.deleteKey(10);

    cout << "Searching 10 after deletion -> index " << h.searchKey(10) << endl;

    return 0;
}
