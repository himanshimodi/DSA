class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> s1map, s2map;
        // Count frequency of characters in s1
        for (char c : s1) {
            s1map[c]++;
        }
        int windowSize = s1.size();
        // Initialize the first window in s2
        for (int i = 0; i < windowSize; i++) {
            s2map[s2[i]]++;
        }
        if (s1map == s2map){
            return true;
        }
        // Slide the window
        for (int i = windowSize; i < s2.size(); i++) {
            s2map[s2[i]]++;              // include new character
            s2map[s2[i - windowSize]]--; // exclude old character

            if (s2map[s2[i - windowSize]] == 0){
                s2map.erase(s2[i - windowSize]); // clean up map
            }
            if (s1map == s2map){
                return true;
            }        
        }
        return false;
    }
};
