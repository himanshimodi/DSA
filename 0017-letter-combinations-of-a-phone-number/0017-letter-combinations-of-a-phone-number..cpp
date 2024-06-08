#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solve(vector<string> &ans, int index, string output, string digits, unordered_map<int, string>& map) {

        // base case
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        // ek case solve krdo, baki recursion sambhal lega 
        int digit = digits[index] - '0';
        string value = map[digit];

        for (int i = 0; i < value.length(); i++) {
            char ch = value[i];
            // include the character
            output.push_back(ch);
            // recursion
            solve(ans, index + 1, output, digits, map); // increment index
            // backtracking
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        string output = "";

        // edge case
        if (digits.length() == 0)
            return ans;

        unordered_map<int, string> map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        solve(ans, index, output, digits, map);

        return ans;
    }
};
