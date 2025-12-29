def count_valid_splits(s: str) -> int:
    n = len(s)
    ans = 0
    for i in range(1, n):
        left = s[:i]
        right = s[i:]
        if left <= right:
            ans += 1
    return ans

# Driver code
if __name__ == "__main__":
    s = input().strip()
    print(count_valid_splits(s))
