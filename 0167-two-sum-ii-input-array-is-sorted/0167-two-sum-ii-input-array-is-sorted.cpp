class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int s=0;
        int e=numbers.size()-1;
        while(s<=e){
            int sum = numbers[s]+numbers[e];
            if(sum>target){
                e--;
            }
            else if(sum<target){
                s++;
            }
            else{
                ans.push_back(s+1);
                ans.push_back(e+1);
                return ans; //immediately return as there is ONLY ONE SOLUTION
            }
        }
        return ans;
    }
};