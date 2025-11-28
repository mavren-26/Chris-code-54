class HashLP:
    def __init__(self, n):
        self.n = n
        self.table = [-1] * n
    
    def insert(self, key):
        idx = key % self.n
        start = idx
        while self.table[idx] not in [-1, -2]:
            idx = (idx + 1) % self.n
            if idx == start: return
        self.table[idx] = key
    
    def search(self, key):
        idx = key % self.n
        start = idx
        while self.table[idx] != -1:
            if self.table[idx] == key:
                return idx
            idx = (idx + 1) % self.n
            if idx == start: break
        return -1
    
    def delete(self, key):
        pos = self.search(key)
        if pos != -1:
            self.table[pos] = -2  # lazy delete
