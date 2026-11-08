#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(std::string s) {
    int l = 0;
    int r = -1;
    int len = s.size();
    int maxLen = 1;
    unordered_map<char, int> freq;


    while (r + 1 < len) {
        if (r + 1 < len && !freq.contains(s[r + 1])) {
            freq[s[++r]]++;
        } else {
            char ch = s[l++];
            freq[ch]--;
            if (!freq[ch]) {
                freq.erase(ch);
            }
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("pwwkew") << endl;

    unordered_map<int, int> freq;
    cout << (freq[0] == 100) << endl;

    cout << freq[0] << endl;
}
