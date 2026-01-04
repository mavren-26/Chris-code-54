#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    void backtrack(vector<string>& ans, string cur, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (open < n) backtrack(ans, cur + "(", open + 1, close, n);
        if (close < open) backtrack(ans, cur + ")", open, close + 1, n);
    }
};
// Example usage:
int main() {
    Solution solution;
    int n = 3;   
    vector<string> result = solution.generateParenthesis(n);
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}
