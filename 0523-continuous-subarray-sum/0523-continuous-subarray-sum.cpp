class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }

        unordered_map<int,int>map; //{sum,index}
        map[0]=-1;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(k!=0){
                sum = sum % k;
            }
            if(map.find(sum)!=map.end()){ //sum is already present in the map
                if(i-map[sum]>=2){
                    //len of subarray should be more than or equal to 2
                    return true;
                }
            }
            else{
                //sum is not already present toh sum ko map mai dal do
                map[sum]=i;
            }
        }
        return false;
    }
};