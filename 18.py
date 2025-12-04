# double_hash_table.py
class DoubleHashTable:
    EMPTY = 0
    OCC = 1
    DEL = 2

    def __init__(self, m):
        self.m = m
        self.keys = [None] * m
        self.state = [DoubleHashTable.EMPTY] * m

    def _h1(self, k):
        return k % self.m

    def _h2(self, k):
        return 1 + (abs(k) % (self.m - 1))

    def search(self, k):
        h1 = self._h1(k)
        h2 = self._h2(k)
        for i in range(self.m):
            idx = (h1 + i * h2) % self.m
            if self.state[idx] == DoubleHashTable.EMPTY:
                return False
            if self.state[idx] == DoubleHashTable.OCC and self.keys[idx] == k:
                return True
        return False

    def insert(self, k):
        if self.search(k):
            return
        h1 = self._h1(k)
        h2 = self._h2(k)
        first_del = -1
        for i in range(self.m):
            idx = (h1 + i * h2) % self.m
            if self.state[idx] == DoubleHashTable.EMPTY:
                if first_del != -1:
                    idx = first_del
                self.keys[idx] = k
                self.state[idx] = DoubleHashTable.OCC
                return
            if self.state[idx] == DoubleHashTable.DEL and first_del == -1:
                first_del = idx
        # table full or rehash needed (not implemented)
        # If first_del available, insert there (already handled)

    def delete(self, k):
        h1 = self._h1(k)
        h2 = self._h2(k)
        for i in range(self.m):
            idx = (h1 + i * h2) % self.m
            if self.state[idx] == DoubleHashTable.EMPTY:
                return
            if self.state[idx] == DoubleHashTable.OCC and self.keys[idx] == k:
                self.state[idx] = DoubleHashTable.DEL
                self.keys[idx] = None
                return

    def dump(self):
        out = []
        for i in range(self.m):
            if self.state[i] == DoubleHashTable.OCC:
                out.append(str(self.keys[i]))
            else:
                out.append("EMPTY")
        return " ".join(out)


def run_problem1():
    import sys
    data = sys.stdin.read().strip().split()
    if not data: return
    it = iter(data)
    m = int(next(it)); n = int(next(it))
    ht = DoubleHashTable(m)
    for _ in range(n):
        cmd = next(it)
        if cmd == "INSERT":
            x = int(next(it)); ht.insert(x)
        elif cmd == "DELETE":
            x = int(next(it)); ht.delete(x)
        elif cmd == "SEARCH":
            x = int(next(it)); print("YES" if ht.search(x) else "NO")
        elif cmd == "PRINT":
            print(ht.dump())


if __name__ == "__main__":
    run_problem1()
