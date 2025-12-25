#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& freeNums, vector<bool>& used,
               vector<int>& path, vector<int>& fixed,
               vector<bool>& blocked, vector<vector<int>>& res) {
    if (path.size() == freeNums.size()) {
        vector<int> perm = fixed;
        int idx = 0;
        for (int i = 0; i < blocked.size(); i++) {
            if (!blocked[i]) perm[i] = path[idx++];
        }
        res.push_back(perm);
        return;
    }

    for (int i = 0; i < freeNums.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && freeNums[i] == freeNums[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        path.push_back(freeNums[i]);
        backtrack(freeNums, used, path, fixed, blocked, res);
        path.pop_back();
        used[i] = false;    
    }
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<bool> blocked = {true, false, false};

    vector<int> freeNums;
    for (int i = 0; i < nums.size(); i++) {
        if (!blocked[i]) freeNums.push_back(nums[i]);
    }

    sort(freeNums.begin(), freeNums.end());
    vector<bool> used(freeNums.size(), false);
    vector<vector<int>> res;
    vector<int> path;

    backtrack(freeNums, used, path, nums, blocked, res);

    for (auto &v : res) {
        cout << "[";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }
}
