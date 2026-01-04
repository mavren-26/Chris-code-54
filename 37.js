function longestBalancedVowelWindow(s, k) {
    const vowels = new Set(["a","e","i","o","u"]);
    let left = 0, vowel = 0, cons = 0, ans = 0;

    for (let right = 0; right < s.length; right++) {
        if (vowels.has(s[right])) vowel++;
        else cons++;

        while (right - left + 1 > k) {
            if (vowels.has(s[left])) vowel--;
            else cons--;
            left++;
        }

        if (vowel === cons) ans = Math.max(ans, right - left + 1);
    }
    return ans;
}
// Driver code  
const fs = require("fs");
const input = fs.readFileSync(0, "utf8").trim().split("\n");
const s = input[0];
const k = parseInt(input[1], 10);
console.log(longestBalancedVowelWindow(s, k));