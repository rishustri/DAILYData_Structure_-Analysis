#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    unordered_map<char, int> lastSeen;
    int left = 0;
    int longest = 0;

    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        char current = s[right];

        // If this character is already in the current window,
        // move the window's left edge past its previous occurrence.
        if (lastSeen.count(current) && lastSeen[current] >= left) {
            left = lastSeen[current] + 1;
        }

        lastSeen[current] = right;
        longest = max(longest, right - left + 1);
    }

    cout << longest << '\n';
    return 0;
}