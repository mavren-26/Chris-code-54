def longestBalancedVowelWindow(s, k):
    vowels = set("aeiou")
    left = 0
    vowel_count = 0
    cons_count = 0
    ans = 0

    for right in range(len(s)):
        if s[right] in vowels:
            vowel_count += 1
        else:
            cons_count += 1

        while right - left + 1 > k:
            if s[left] in vowels:
                vowel_count -= 1
            else:
                cons_count -= 1
            left += 1

        if vowel_count == cons_count:
            ans = max(ans, right - left + 1)

    return ans
# Example usage:
s = "aeioubcdfg"
k = 5
print(longestBalancedVowelWindow(s, k))