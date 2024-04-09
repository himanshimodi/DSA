class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0}; // because we consider only small letters

        // putting letters into hash map and counting the num of times each character has occured
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }

        // finding most frequent character
        char max_freq_char = 'a';
        int max_freq = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > max_freq) {
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }

        // placing characters begins now
        int index = 0;
        while (hash[max_freq_char - 'a'] > 0 && index < s.size()) {
            s[index] = max_freq_char;
            hash[max_freq_char - 'a']--;
            index += 2;
        }

        // could not place the max freq character in one go
        if (hash[max_freq_char - 'a'] > 0) {
            return "";
        }

        // lets place the rest of the characters
        for (int i = 0; i < 26; i++) {
            while (hash[i] > 0) {
                if (index >= s.size()) {
                    index = 1;
                }
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};
