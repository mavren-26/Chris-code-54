function countValidSplits(s) {
    let ans = 0;
    for (let i = 1; i < s.length; i++) {
        let left = s.slice(0, i);
        let right = s.slice(i);
        if (left <= right) ans++;
    }
    return ans;
}

// Driver code
const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
console.log(countValidSplits(s));
