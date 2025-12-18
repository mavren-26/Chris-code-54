#include <iostream>
#include <vector>
using namespace std;

void backtrack(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(path);
        return;
    }

    // include
    path.push_back(nums[index]);
    backtrack(index + 1, nums, path, result);

    // exclude
    path.pop_back();
    backtrack(index + 1, nums, path, result);
}

int main() {
    vector<int> nums = {1, 2};
    vector<vector<int>> result;
    vector<int> path;

    backtrack(0, nums, path, result);

    for (auto& subset : result) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }
}
