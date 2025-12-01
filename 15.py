def count_collisions(values, size):
    table = [None] * size
    collisions = 0

    for v in values:
        idx = v % size
        while table[idx] is not None:
            collisions += 1
            idx = (idx + 1) % size
        table[idx] = v

    return collisions

print(count_collisions([12, 22, 32, 42], 10))
