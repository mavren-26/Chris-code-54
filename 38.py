from collections import defaultdict

def minDistinctInWindow(nums, k):
    freq = defaultdict(int)
    left = 0
    distinct = 0
    ans = float("inf")

    for right in range(len(nums)):
        freq[nums[right]] += 1
        if freq[nums[right]] == 1:
            distinct += 1

        if right - left + 1 == k:
            ans = min(ans, distinct)
            freq[nums[left]] -= 1
            if freq[nums[left]] == 0:
                distinct -= 1
            left += 1

    return ans
# Example usage:
nums = [1, 2, 1, 3, 4, 2, 3]
k = 4
print(minDistinctInWindow(nums, k)) # Output: 3
