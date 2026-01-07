def generateParenthesis(n):
    ans = []

    def backtrack(cur, open_c, close_c):
        if len(cur) == 2 * n:
            ans.append(cur)
            return
        
        if open_c < n:
            backtrack(cur + "(", open_c + 1, close_c)
        if close_c < open_c:
            backtrack(cur + ")", open_c, close_c + 1)

    backtrack("", 0, 0)
    return ans
# Example usage:
n = 5
print(generateParenthesis(n)) 