#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int minDistinctInWindow(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    int left = 0, distinct = 0;
    int ans = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;
        if (freq[nums[right]] == 1) distinct++;

        if (right - left + 1 == k) {
            ans = min(ans, distinct);
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) distinct--;
            left++;
        }
    }
    return ans;
}
// Example usage
int main() {
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    cout << minDistinctInWindow(nums, k) << endl; // Output: 3
    return 0;
}