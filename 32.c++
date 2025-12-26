#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> need;
    for(char c : t) need[c]++;

    int missing = t.size();
    int left = 0, start = 0, minLen = INT_MAX;

    for(int right = 0; right < (int)s.size(); right++) {
        if(need[s[right]] > 0) missing--;
        need[s[right]]--;

        while(missing == 0) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            need[s[left]]++;
            if(need[s[left]] > 0) missing++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t);
    return 0;
}
