class Solution {
public: //TC=O(n) & SC=O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map; // <sum,freq of this sum>
        map[0]=1;
        int sum=0,count =0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(map.find(sum-k)!=map.end()){
                // if sum-k already exists in the map
                count ++;
                map[sum]++;
            }
            else{
                //push in the map
                map[sum] ++;
            }
        }
        return count;
    }
};