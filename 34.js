function smallestRotation(s) {
    let best = s;
    for (let i = 1; i < s.length; i++) {
        let rotated = s.slice(i) + s.slice(0, i);
        if (rotated < best) best = rotated;
    }
    return best;
}

// Driver code
const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
console.log(smallestRotation(s));
