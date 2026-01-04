function countNiceSubarrays(nums, k) {
    let left = 0, sum = 0, ans = 0;

    for (let right = 0; right < nums.length; right++) {
        sum += nums[right];

        while (left <= right && sum >= k) {
            sum -= nums[left];
            left++;
        }

        ans += (right - left + 1);
    }
    return ans;
}
// Driver code
const fs = require("fs");
const input = fs.readFileSync(0, "utf8").trim().split("\n");
const nums = input[0].split(" ").map(Number);
const k = parseInt(input[1], 10);
console.log(countNiceSubarrays(nums, k));
