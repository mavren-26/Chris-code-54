#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& path, vector<vector<int>>& ans) {

        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if (!path.empty() && path.back() == nums[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, ans);
            path.pop_back();
            used[i] = false;
        }
    }
};
// Example usage:
int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = solution.permuteUnique(nums);
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
