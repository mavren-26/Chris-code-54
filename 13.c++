#include <iostream>
#include <vector>
using namespace std;

vector<int> countProbes(vector<int> &arr, int n) {
    vector<int> table(n, -1);
    vector<int> res;

    for (int key : arr) {
        int idx = key % n;
        int start = idx;
        int probes = 1;

        while (table[idx] != -1) {
            idx = (idx + 1) % n;
            probes++;
            if (idx == start) break;
        }

        table[idx] = key;
        res.push_back(probes);
    }
    return res;
}

int main() {
    vector<int> arr = {10, 20, 30, 25, 35};
    vector<int> r = countProbes(arr, 10);

    for (int x : r) cout << x << " ";
}
