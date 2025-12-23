def subsetsWithTarget(nums, target):
    nums.sort()
    res = []

    def backtrack(start, path, curr_sum):
        if curr_sum == target:
            res.append(path[:])
            return
        if curr_sum > target:
            return

        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i-1]:
                continue
            backtrack(i + 1, path + [nums[i]], curr_sum + nums[i])

    backtrack(0, [], 0)
    return res
