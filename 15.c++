#include <iostream>
#include <vector>
using namespace std;

int countCollisions(vector<int> &values, int size) {
    vector<int> table(size, -1);
    int collisions = 0;

    for (int v : values) {
        int idx = v % size;

        while (table[idx] != -1) {
            collisions++;
            idx = (idx + 1) % size;
        }
        table[idx] = v;
    }
    return collisions;
}

int main() {
    vector<int> values = {12, 22, 32, 42};
    cout << countCollisions(values, 10) << endl;
    return 0;
}
