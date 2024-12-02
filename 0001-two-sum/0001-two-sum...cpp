class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        vector<int>ans;
        int sum =0;
        vector<pair<int,int>> data;
        for(int i=0; i<nums.size();i++){
            int index = i;
            int val = nums[i];
            data.push_back({val,index});
        }
        sort(data.begin(),data.end());

        //apply 2 ptr approach
        while(s<e){
            sum = data[s].first + data[e].first;
            if(sum == target){
                ans.push_back(data[s].second);
                ans.push_back(data[e].second);
            }
            if(sum > target){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
    }
};