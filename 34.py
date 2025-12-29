def smallest_rotation(s: str) -> str:
    n = len(s)
    best = s
    for i in range(1, n):
        rotated = s[i:] + s[:i]
        if rotated < best:
            best = rotated
    return best

# Driver code
if __name__ == "__main__":
    s = input().strip()
    print(smallest_rotation(s))
