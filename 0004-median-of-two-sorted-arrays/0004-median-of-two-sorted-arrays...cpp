class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        vector<int>merged;
        //merge both arrays into one
        for(int i=0;i<n;i++){
            merged.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            merged.push_back(nums2[i]);
        }

        //sort the new array
        sort(merged.begin(),merged.end());
        int total = merged.size();

        if(total%2 == 1){
            return (merged[total/2]);
        }
        else{
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return ((middle1)+(middle2))/2.0;
        }

    }
};