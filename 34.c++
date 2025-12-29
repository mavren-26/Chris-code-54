#include <iostream>
#include <string>
using namespace std;

string smallestRotation(string s) {
    string best = s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        string rotated = s.substr(i) + s.substr(0, i);
        if (rotated < best) best = rotated;
    }
    return best;
}

int main() {
    string s;
    cin >> s;
    cout << smallestRotation(s);
    return 0;
}
