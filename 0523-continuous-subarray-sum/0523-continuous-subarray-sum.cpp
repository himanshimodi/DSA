class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }
        unordered_map<int,int>map;
        map[0]=-1;
        int sum =0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(k!=0){
                sum = sum %k;
            }
            if(map.find(sum)!= map.end()){
                //present in map
                return true;
            }
            else{
                //push it in the map
                map[sum]=i;
            }
        }
        return false;
    }
};