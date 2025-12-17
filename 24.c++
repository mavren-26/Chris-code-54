#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int currSum = 0, count = 0;

    for (int num : nums) {
        currSum += num;
        if (prefixCount.count(currSum - k)) {
            count += prefixCount[currSum - k];
        }
        prefixCount[currSum]++;
    }
    return count;
}
