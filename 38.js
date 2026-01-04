function minDistinctInWindow(nums, k) {
    let map = new Map();
    let left = 0, distinct = 0, ans = Infinity;

    for (let right = 0; right < nums.length; right++) {
        map.set(nums[right], (map.get(nums[right]) || 0) + 1);
        if (map.get(nums[right]) === 1) distinct++;

        if (right - left + 1 === k) {
            ans = Math.min(ans, distinct);
            map.set(nums[left], map.get(nums[left]) - 1);
            if (map.get(nums[left]) === 0) distinct--;
            left++;
        }
    }
    return ans;
}
// Driver code
const fs = require("fs");
const input = fs.readFileSync(0, "utf8").trim().split("\n");
const nums = input[0].split(" ").map(Number);
const k = parseInt(input[1], 10);
console.log(minDistinctInWindow(nums, k));
