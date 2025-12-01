#include <iostream>
#include <vector>
using namespace std;

class LinearProbingHash {
    int size;
    vector<string> table;

public:
    LinearProbingHash(int n) : size(n), table(n, "NULL") {}

    void insert(int value) {
        int idx = value % size;
        int start = idx;

        while (table[idx] != "NULL" && table[idx] != "DEL") {
            if (stoi(table[idx]) == value) return;
            idx = (idx + 1) % size;
            if (idx == start) return;
        }
        table[idx] = to_string(value);
    }

    int search(int value) {
        int idx = value % size;
        int start = idx;

        while (table[idx] != "NULL") {
            if (table[idx] != "DEL" && stoi(table[idx]) == value)
                return idx;
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        return -1;
    }

    void remove(int value) {
        int idx = search(value);
        if (idx != -1) table[idx] = "DEL";
    }
};

int main() {
    LinearProbingHash h(10);
    h.insert(10);
    h.insert(20);
    h.insert(17);
    cout << h.search(17) << endl;
    h.remove(20);
    cout << h.search(20) << endl;
    return 0;
}
