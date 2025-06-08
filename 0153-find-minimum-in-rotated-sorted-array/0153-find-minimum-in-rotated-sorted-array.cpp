class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1; // Minimum is in the right half
            } else {
                e = mid; // Minimum is in the left half or at mid
            }
        }
        return nums[s]; // or nums[e], since s == e
    }
};
