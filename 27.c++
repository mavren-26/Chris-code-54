#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, int remaining, vector<int>& candidates,
               vector<int>& path, vector<vector<int>>& result) {
    if (remaining == 0) {
        result.push_back(path);
        return;
    }
    if (remaining < 0) return;

    for (int i = start; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        backtrack(i, remaining - candidates[i], candidates, path, result);
        path.pop_back();
    }
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result;
    vector<int> path;

    backtrack(0, target, candidates, path, result);

    for (auto& comb : result) {
        cout << "[ ";
        for (int x : comb) cout << x << " ";
        cout << "]\n";
    }
}
