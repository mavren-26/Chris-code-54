function subsetsWithTarget(nums, target) {
    nums.sort((a, b) => a - b);
    const res = [];

    function backtrack(start, path, sum) {
        if (sum === target) {
            res.push([...path]);
            return;
        }
        if (sum > target) return;

        for (let i = start; i < nums.length; i++) {
            if (i > start && nums[i] === nums[i - 1]) continue;
            path.push(nums[i]);
            backtrack(i + 1, path, sum + nums[i]);
            path.pop();
        }
    }

    backtrack(0, [], 0);
    return res;
}
