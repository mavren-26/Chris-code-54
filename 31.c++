#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &p : mp) result.push_back(p.second);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) cin >> strs[i];

    vector<vector<string>> res = groupAnagrams(strs);

    for (auto &group : res) {
        cout << "[ ";
        for (auto &w : group) cout << w << " ";
        cout << "]";
    }
    return 0;
}
