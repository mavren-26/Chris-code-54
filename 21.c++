#include <iostream>
#include <vector>
using namespace std;

vector<int> compact(const vector<int>& arr) {
    vector<int> result;
    for (int x : arr)
        if (x != -1) result.push_back(x);
    return result;
}

int main() {
    vector<int> arr = {5, -1, 7, 9, -1, 3};
    vector<int> result = compact(arr);

    for (int x : result) cout << x << " ";
}
