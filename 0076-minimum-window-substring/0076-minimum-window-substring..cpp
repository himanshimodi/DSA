class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        int ansIndex = -1;
        int ansLen = INT_MAX;

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        // Fill values in tmap
        for (auto i : t) {
            tmap[i]++;
        }

        int start = 0, end = 0, c = 0;

        // Variable size window logic
        while (end < s.length()) {
            char ch = s[end];
            smap[ch]++;
            // If character matches
            if (smap[ch] <= tmap[ch]) {
                c++;
            }

            // If all characters are matched
            if (c == t.length()) {
                // Minimize the window (shrink the window)
                while (smap[s[start]] > tmap[s[start]] || tmap[s[start]] == 0) {
                    if (smap[s[start]] > tmap[s[start]]) {
                        smap[s[start]]--;
                    }
                    start++;
                }

                // Store the result
                int windowLen = end - start + 1;
                if (windowLen < ansLen) {
                    ansLen = windowLen;
                    ansIndex = start;
                }
            }
            // Expand the window
            end++;
        }

        // If no valid window is found
        if (ansIndex == -1) {
            return "";
        } else {
            return s.substr(ansIndex, ansLen);
        }
    }
};
