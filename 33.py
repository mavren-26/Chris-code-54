def countSubstrings(s: str) -> int:
    def expand(l, r):
        count = 0
        while l >= 0 and r < len(s) and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        return count

    ans = 0
    for i in range(len(s)):
        ans += expand(i, i)     # odd
        ans += expand(i, i + 1) # even
    return ans
