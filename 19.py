class DoubleHashSet:
    EMPTY = 0
    OCC = 1
    DEL = 2

    def __init__(self, m):
        self.m = m
        self.keys = [None] * m
        self.state = [DoubleHashSet.EMPTY] * m
        self.distinct = 0

    def _h1(self, k):
        return k % self.m

    def _h2(self, k):
        return 1 + (abs(k) % (self.m - 1))

    def search(self, k):
        a = self._h1(k)
        b = self._h2(k)
        for i in range(self.m):
            idx = (a + i * b) % self.m
            if self.state[idx] == DoubleHashSet.EMPTY:
                return False
            if self.state[idx] == DoubleHashSet.OCC and self.keys[idx] == k:
                return True
        return False

    def insert(self, k):
        if self.search(k):
            return  # already exists

        a = self._h1(k)
        b = self._h2(k)

        first_del = -1
        for i in range(self.m):
            idx = (a + i * b) % self.m
            if self.state[idx] == DoubleHashSet.EMPTY:
                insert_pos = first_del if first_del != -1 else idx
                self.keys[insert_pos] = k
                self.state[insert_pos] = DoubleHashSet.OCC
                self.distinct += 1
                return
            if self.state[idx] == DoubleHashSet.DEL and first_del == -1:
                first_del = idx

        # fallback (insert at first tombstone)
        if first_del != -1:
            self.keys[first_del] = k
            self.state[first_del] = DoubleHashSet.OCC
            self.distinct += 1


def main():
    import sys
    data = sys.stdin.read().strip().split()
    m = int(data[0])
    q = int(data[1])
    s = DoubleHashSet(m)

    idx = 2
    for _ in range(q):
        x = int(data[idx]); idx += 1
        s.insert(x)
        print(s.distinct)

if __name__ == "__main__":
    main()
