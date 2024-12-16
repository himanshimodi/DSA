class Solution {
public:

    //using DNC here, better way is Kadane's Algo

    // int helper(vector<int>&v, int start, int end){

    //     //base case
    //     if(start == end){
    //         return v[start];
    //     }

    //     int maxLBS = INT_MIN;
    //     int maxRBS = INT_MIN;
    //     int mid = start + (end-start)/2;

    //     int maxLeftSum = helper(v,start,mid);
    //     int maxRightSum = helper(v,mid+1,end);

    //     //Max cross border sum - CBS
    //     int LBS = 0;
    //     int RBS = 0;

    //     //LBS
    //     for(int i = mid; i>=start; i--){
    //         LBS += v[i];
    //         if(LBS > maxLBS){
    //             maxLBS = LBS;
    //         }
    //     }

    //     for(int i = mid+1; i<=end; i++){
    //         RBS += v[i];
    //         if(RBS > maxRBS){
    //             maxRBS = RBS;
    //         }
    //     }

    //     int CBS = maxLBS + maxRBS;
    //     return max(maxLeftSum, max(maxRightSum,CBS));
    // }

    //THE FAMOUS KADANE'S ALGO. TC-O(N)

    int kadaneAlgo(vector<int>&nums){
        int ans = INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            sum+=ele;
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
    
    int maxSubArray(vector<int> &nums){
        // return helper(nums, 0, nums.size()-1);
        return kadaneAlgo(nums);
    }
};