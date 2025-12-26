#include <iostream>
#include <string>
using namespace std;

int countSubstrings(string s) {
    auto expand = [&](int l, int r) {
        int count = 0;
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            count++;
            l--; r++;
        }
        return count;
    };

    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        ans += expand(i, i);
        ans += expand(i, i + 1);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << countSubstrings(s);
    return 0;
}
