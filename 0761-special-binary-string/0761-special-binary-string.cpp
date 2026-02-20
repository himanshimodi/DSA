class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
        int count = 0;
        int left = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '1')
                count++;
            else
                count--;

            // When count becomes 0, we found a special substring
            if (count == 0) {

                // Get inner substring (remove outer 1 and 0)
                string inner = s.substr(left + 1, i - left - 1);

                // Recursively process inner part
                string temp = "1" + makeLargestSpecial(inner) + "0";

                blocks.push_back(temp);

                left = i + 1;   // move start pointer
            }
        }

        // Sort in descending order
        sort(blocks.begin(), blocks.end());
        reverse(blocks.begin(), blocks.end());

        // Combine all parts
        string answer = "";
        for (int i = 0; i < blocks.size(); i++) {
            answer += blocks[i];
        }

        return answer;
    }
};