def count_probes(arr, n):
    table = [-1] * n
    result = []

    for key in arr:
        idx = key % n
        start = idx
        probes = 1

        while table[idx] != -1:
            idx = (idx + 1) % n
            probes += 1
            if idx == start:
                break
        
        table[idx] = key
        result.append(probes)

    return result

print(count_probes([10, 20, 30, 25, 30], 10))
