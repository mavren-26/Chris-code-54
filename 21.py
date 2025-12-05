def compact(arr):
    return [x for x in arr if x != -1]

print(compact([5, -1, 7, 9, -1, 3]))
