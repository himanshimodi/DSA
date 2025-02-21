class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // BC
    if (k <= 1) return 0;

    int totalCount = 0;
    int product = 1;

    //maintain a sliding window
    for (int left = 0, right = 0; right < nums.size(); right++) {
      // Expand the window 
      product *= nums[right];

      // Shrink the window 
      while (product >= k) {
        // Remove the element at the left pointer from the product
        product /= nums[left];
        left++;
      }
      // Update the total count by adding the number of valid subarrays with the current window size
      totalCount += right - left + 1;  // right - left + 1 represents the current window size
    }
    return totalCount;
  }
};