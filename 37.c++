#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int longestBalancedVowelWindow(string s, int k) {
    unordered_set<char> vowels = {'a','e','i','o','u'};
    int left = 0, vowel = 0, cons = 0, ans = 0;

    for (int right = 0; right < s.size(); right++) {
        if (vowels.count(s[right])) vowel++;
        else cons++;

        while (right - left + 1 > k) {
            if (vowels.count(s[left])) vowel--;
            else cons--;
            left++;
        }

        if (vowel == cons) ans = max(ans, right - left + 1);
    }
    return ans;
}
// Example usage
int main() {
    string s = "aeioubcdfg";
    int k = 5;
    cout << longestBalancedVowelWindow(s, k) << endl;
    return 0;
}
