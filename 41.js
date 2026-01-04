function permuteUnique(nums) {
    nums.sort((a,b)=>a-b);
    let used = new Array(nums.length).fill(false);
    let ans = [];

    function backtrack(path) {
        if (path.length === nums.length) {
            ans.push([...path]);
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] === nums[i-1] && !used[i-1]) continue;
            if (path.length && path[path.length-1] === nums[i]) continue;

            used[i] = true;
            path.push(nums[i]);
            backtrack(path);
            path.pop();
            used[i] = false;
        }
    }

    backtrack([]);
    return ans;
}
// Example usage:
const nums = [1, 1, 2];
console.log(permuteUnique(nums));
