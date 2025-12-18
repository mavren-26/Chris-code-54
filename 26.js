function subsets(nums) {
    const result = [];
    const path = [];

    function backtrack(index) {
        if (index === nums.length) {
            result.push([...path]);
            return;
        }

        // include
        path.push(nums[index]);
        backtrack(index + 1);

        // exclude
        path.pop();
        backtrack(index + 1);
    }

    backtrack(0);
    return result;
}
