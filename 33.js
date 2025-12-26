function countSubstrings(s) {
    function expand(l, r) {
        let count = 0;
        while (l >= 0 && r < s.length && s[l] === s[r]) {
            count++;
            l--; r++;
        }
        return count;
    }

    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        ans += expand(i, i);
        ans += expand(i, i + 1);
    }
    return ans;
}
