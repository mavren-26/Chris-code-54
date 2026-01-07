def countNiceSubarrays(nums, k):
    left = 0
    curr = 0
    ans = 0

    for right in range(len(nums)):
        curr += nums[right]

        while left <= right and curr >= k:
            curr -= nums[left]
            left += 1

        ans += (right - left + 1)

    return ans
# Example usage:
nums = [1, 2, 3, 4, 5,6,7]
k = 5
print(countNiceSubarrays(nums, k))  # Output: 9
