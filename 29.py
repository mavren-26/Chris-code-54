def permuteWithBlocked(nums, blocked):
    res = []
    n = len(nums)
    fixed = nums[:]
    free = [nums[i] for i in range(n) if not blocked[i]]
    free.sort()
    used = [False] * len(free)

    def backtrack(path):
        if len(path) == len(free):
            idx = 0
            perm = fixed[:]
            for i in range(n):
                if not blocked[i]:
                    perm[i] = path[idx]
                    idx += 1
            res.append(perm)
            return

        for i in range(len(free)):
            if used[i]: continue
            if i > 0 and free[i] == free[i-1] and not used[i-1]:
                continue
            used[i] = True
            backtrack(path + [free[i]])
            used[i] = False

    backtrack([])
    return res
