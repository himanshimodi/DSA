#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};  // Frequency array to count occurrences of each character
        queue<int> q;  // Queue to store the indices of characters in the order they appear

        // Iterate through the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;  // Increment frequency of the character
            q.push(i);  // Push the index of the character into the queue

            // Remove characters from the front of the queue while their frequency is greater than 1
            while (!q.empty() && freq[s[q.front()] - 'a'] > 1) {
                q.pop();
            }
        }

        // If the queue is empty, there are no unique characters, return -1
        // Otherwise, return the index of the first unique character
        return q.empty() ? -1 : q.front();
    }
};
