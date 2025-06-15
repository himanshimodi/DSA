class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; 
        mp[0]=-1; 
        //change all zeros to -1
        for(int i=0;i<nums.size();i++){
            nums[i]==0?nums[i]=-1:nums[i]=1;
        }
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];            
            if(mp.find(sum)!=mp.end()){
                //present
                res=max(res,i-mp[sum]);
            }
            else{
                //adding value to our map
                mp[sum]=i;
            }
        }
        return res;
    }
};