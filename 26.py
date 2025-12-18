def subsets(nums):
    result = []
    path = []

    def backtrack(index):
        if index == len(nums):
            result.append(path.copy())
            return
        
        # include current element
        path.append(nums[index])
        backtrack(index + 1)

        # exclude current element
        path.pop()
        backtrack(index + 1)

    backtrack(0)
    return result
