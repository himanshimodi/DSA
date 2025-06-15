class Solution {
public:
    // SIMILAR SUMS ARE PAINTER'S PARTITION PROBLEM ON GFG AND 
    // ALLOCATE MINIMUM BOOK PROBLEM ON GFG
    bool isPossible(vector<int>& nums, int k,int mid){
        int subarray=1;
        int arrelement=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){ //first element he more than mid hai
                return false;
            }

            if(arrelement+nums[i]<=mid){
                arrelement+=nums[i];
            }
            else{
                subarray++;
                if(subarray>k){
                    return false;
                }
                arrelement=0;
                arrelement+=nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =-1;
        int s=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int e=sum;
        int mid = s+(e-s)/2;

        if(k>nums.size()){
            return -1;
        }

        while(s<=e){
            if(isPossible(nums,k,mid)==true){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};