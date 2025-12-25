def longestPalindrome(s: str) -> str:
    if len(s) < 2:
        return s

    start = 0
    max_len = 1

    def expand(l, r):
        nonlocal start, max_len
        while l >= 0 and r < len(s) and s[l] == s[r]:
            if r - l + 1 > max_len:
                start = l
                max_len = r - l + 1
            l -= 1
            r += 1

    for i in range(len(s)):
        expand(i, i)       # odd
        expand(i, i + 1)   # even

    return s[start:start + max_len]
