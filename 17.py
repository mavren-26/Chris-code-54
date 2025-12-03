class StringHashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash(self, s):
        return sum(ord(c) for c in s) % self.size

    def insert(self, key):
        idx = self.hash(key)
        if key not in self.table[idx]:
            self.table[idx].append(key)

    def search(self, key):
        return key in self.table[self.hash(key)]

    def get_chain(self, key):
        return self.table[self.hash(key)]
