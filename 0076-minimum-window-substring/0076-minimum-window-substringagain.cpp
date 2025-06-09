class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        int ansIndex = -1;
        int ansLen = INT_MAX;
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        int start = 0;
        int end = 0; // variable size ki window hai thats why
        int count = 0;
        for (auto i : t) {
            tmap[i]++;
        }
        while (end < s.size()) { // variable size window
            char ch = s[end];
            smap[ch]++;

            // if character matches
            if (smap[ch] <= tmap[ch]) {
                count++;
            }

            if (count == t.size()) {
                while (smap[s[start]] > tmap[s[start]]) {
                    if (smap[s[start]] > tmap[s[start]]) {
                        // shrink krlo so minimise
                        smap[s[start]]--;
                    }
                    start++;
                }
                int windowLen = end - start + 1;
                if (windowLen < ansLen) {
                    ansLen = windowLen;
                    ansIndex = start;
                }
            }
            end++;
        }
        if (ansIndex == -1) {
            return "";
        } else {
            return s.substr(ansIndex, ansLen);
        }
    }
};