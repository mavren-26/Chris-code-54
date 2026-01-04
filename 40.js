function generateParenthesis(n) {
    let ans = [];

    function backtrack(cur, open, close) {
        if (cur.length === 2 * n) {
            ans.push(cur);
            return;
        }
        if (open < n) backtrack(cur + "(", open + 1, close);
        if (close < open) backtrack(cur + ")", open, close + 1);
    }

    backtrack("", 0, 0);
    return ans;
}
// Example usage:
const n = 3;   
console.log(generateParenthesis(n));
