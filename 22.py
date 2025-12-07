# Tombstone Skyline - Python solution
import bisect
import sys

def min_removals_to_mountain(h):
    n = len(h)
    if n < 3:
        return -1

    # LIS lengths ending at i (strict)
    tails = []
    L = [0]*n
    for i, val in enumerate(h):
        pos = bisect.bisect_left(tails, val)  # strict increasing -> lower_bound
        if pos == len(tails):
            tails.append(val)
        else:
            tails[pos] = val
        L[i] = pos + 1

    # LIS lengths starting at i on reversed array -> gives decreasing lengths from i
    tails = []
    R = [0]*n
    for idx in range(n-1, -1, -1):
        val = h[idx]
        pos = bisect.bisect_left(tails, val)
        if pos == len(tails):
            tails.append(val)
        else:
            tails[pos] = val
        R[idx] = pos + 1

    max_mountain = 0
    for i in range(n):
        # need at least one on each side -> L[i] >= 2 and R[i] >= 2
        if L[i] >= 2 and R[i] >= 2:
            length = L[i] + R[i] - 1
            if length > max_mountain:
                max_mountain = length

    if max_mountain == 0:
        return -1
    return n - max_mountain

if __name__ == "__main__":
    data = sys.stdin.read().strip().split()
    if not data:
        # simple example
        h = [2,1,4,7,3,2,5]
        print(min_removals_to_mountain(h))  # expected 2
    else:
        it = iter(data)
        n = int(next(it))
        h = [int(next(it)) for _ in range(n)]
        print(min_removals_to_mountain(h))
