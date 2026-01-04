#include <iostream>
#include <vector>
using namespace std;

long long countNiceSubarrays(vector<int>& nums, long long k) {
    int left = 0;
    long long sum = 0, ans = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (left <= right && sum >= k) {
            sum -= nums[left];
            left++;
        }

        ans += (right - left + 1);
    }
    return ans;
}
// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    long long k = 5;
    cout << countNiceSubarrays(nums, k) << endl;  // Output: 9
    return 0;
}
