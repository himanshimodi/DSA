class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        unordered_map<char, int> freqMap;
        priority_queue<pair<char, int>> maxHeap;

        // Count character frequency
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Push into maxHeap
        for (auto entry : freqMap) {
            maxHeap.push({entry.first, entry.second});
        }

        while (!maxHeap.empty()) {
            char currchar = maxHeap.top().first;
            int currcount = maxHeap.top().second;
            maxHeap.pop();

            int useCount = min(currcount, repeatLimit);
            for (int i = 0; i < useCount; i++) {
                ans += currchar;
            }
            currcount -= useCount;

            if (currcount > 0) {
                if (maxHeap.empty()) {
                    break;
                }

                // Get the next character
                char nextchar = maxHeap.top().first;
                int nextcount = maxHeap.top().second;
                maxHeap.pop();

                ans += nextchar;
                nextcount--;//this happens only one time

                // Push remaining counts back to the heap
                maxHeap.push({currchar, currcount});
                if (nextcount > 0) {
                    maxHeap.push({nextchar, nextcount});
                }
            }
        }

        return ans;
    }
};