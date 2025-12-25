#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.length() < 2) return s;

    int start = 0, maxLen = 1;

    auto expand = [&](int l, int r) {
        while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    };

    for (int i = 0; i < (int)s.length(); i++) {
        expand(i, i);       // odd
        expand(i, i + 1);   // even
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
