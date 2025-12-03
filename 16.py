class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash(self, key):
        return key % self.size

    def insert(self, key):
        idx = self.hash(key)
        if key not in self.table[idx]:
            self.table[idx].append(key)

    def search(self, key):
        idx = self.hash(key)
        return key in self.table[idx]

    def remove(self, key):
        idx = self.hash(key)
        if key in self.table[idx]:
            self.table[idx].remove(key)
