# Falling Tombstones - Python solution
from collections import deque
import sys

def simulate_falling(s, T):
    n = len(s)
    standing = [c == '1' for c in s]
    cnt = [0]*n
    for i in range(n):
        if i-1 >= 0 and standing[i-1]:
            cnt[i] += 1
        if i+1 < n and standing[i+1]:
            cnt[i] += 1
    q = deque()
    for i in range(n):
        if standing[i] and cnt[i] < T:
            q.append(i)
    days = 0
    while q:
        days += 1
        next_q = deque()
        # process all current failures simultaneously
        while q:
            i = q.popleft()
            if not standing[i]:
                continue
            standing[i] = False
            # update neighbors
            for nb in (i-1, i+1):
                if 0 <= nb < n and standing[nb]:
                    cnt[nb] -= 1
                    if cnt[nb] < T:
                        next_q.append(nb)
        q = next_q
    final = ''.join('1' if x else '0' for x in standing)
    return final, days

if __name__ == "__main__":
    data = sys.stdin.read().strip().split()
    if not data:
        s = "1101101"; T = 1
        final, days = simulate_falling(s, T)
        print(final)
        print(days)
    else:
        s = data[0].strip()
        T = int(data[1])
        final, days = simulate_falling(s, T)
        print(final)
        print(days)
