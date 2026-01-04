def permuteUnique(nums):
    nums.sort()
    used = [False] * len(nums)
    ans = []

    def backtrack(path):
        if len(path) == len(nums):
            ans.append(path[:])
            return
        
        for i in range(len(nums)):
            if used[i]:
                continue
            if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                continue
            if path and path[-1] == nums[i]:
                continue

            used[i] = True
            path.append(nums[i])
            backtrack(path)
            path.pop()
            used[i] = False

    backtrack([])
    return ans
# Example usage:
nums = [1, 1, 2]
print(permuteUnique(nums))  
