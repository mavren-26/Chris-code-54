class LinearProbingHash:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.deleted = "<DEL>"

    def insert(self, value):
        idx = value % self.size
        start = idx
        while self.table[idx] not in (None, self.deleted):
            if self.table[idx] == value:
                return  # already exists
            idx = (idx + 1) % self.size
            if idx == start:
                return  # full
        self.table[idx] = value

    def search(self, value):
        idx = value % self.size
        start = idx
        while self.table[idx] is not None:
            if self.table[idx] == value:
                return idx
            idx = (idx + 1) % self.size
            if idx == start:
                break
        return -1

    def delete(self, value):
        idx = self.search(value)
        if idx != -1:
            self.table[idx] = self.deleted


# Driver Example
h = LinearProbingHash(10)
h.insert(10)
h.insert(20)
h.insert(17)
print(h.search(17))
h.delete(20)
print(h.search(20))
