def count_active(arr):
    return sum(1 for x in arr if x == 1)

arr = [1, -1, 0, 1, 1, -1]
print(count_active(arr))
