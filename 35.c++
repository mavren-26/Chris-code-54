#include <iostream>
#include <string>
using namespace std;

int countValidSplits(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (left <= right) ans++;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << countValidSplits(s);
    return 0;
}
