#include <iostream>
#include <vector>
using namespace std;

int countActive(const vector<int>& arr) {
    int count = 0;
    for (int x : arr) if (x == 1) count++;
    return count;
}

int main() {
    vector<int> arr = {1, -1, 0, 1, 1, -1};
    cout << countActive(arr) << endl;
}
