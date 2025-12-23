#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& nums, int target, int start,
               vector<int>& path, vector<vector<int>>& res, int sum) {
    if (sum == target) {
        res.push_back(path);
        return;
    }
    if (sum > target) return;

    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        backtrack(nums, target, i + 1, path, res, sum + nums[i]);
        path.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 2, 3};
    int target = 5;
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums, target, 0, path, res, 0);

    for (auto &v : res) {
        cout << "[";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }
}
