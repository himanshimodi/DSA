class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        int n = nums.size();
        
        unordered_map<int, int> mp;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Initialize maxHeaps with the first 'k' elements
        for (int i = 0; i < k; i++) {
            maxHeap.push(nums[i]);
        }

        // Balance the heaps, moving half of the elements from maxHeap to minHeap
        for (int i = 0; i < (k / 2); i++) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Process the sliding window
        for (int i = k; i < n; i++) {
            // Add the current median to the result vector
            if (k & 1) {  // If k is odd, median is the top of maxh
                medians.push_back(maxHeap.top() * 1.0);
            } else {  // If k is even, median is the average of tops of both heaps
                medians.push_back(((double)maxHeap.top() + (double)minHeap.top()) / 2);
            }

            int p = nums[i - k];  // Element sliding out of the window
            int q = nums[i];      // New element entering the window

            int balance = 0; // Track the balance between the heaps
            
            // Remove element 'p' from the appropriate heap
            if (p <= maxHeap.top()) {
                balance--;  // Decrease balance when removing from maxHeap
                if (p == maxHeap.top()) {
                    maxHeap.pop();
                } else {
                    mp[p]++;  // Mark p for later deletion
                }
            } else {
                balance++;  // Increase balance when removing from minHeap
                if (p == minHeap.top()) {
                    minHeap.pop();
                } else {
                    mp[p]++;  // Mark p for later deletion
                }
            }
            
            // Insert element 'q' into the appropriate heap
            if (!maxHeap.empty() && q <= maxHeap.top()) {
                maxHeap.push(q);
                balance++;  // Increase balance when inserting into maxHeap
            } else {
                minHeap.push(q);
                balance--;  // Decrease balance when inserting into minHeap
            }
            
            // Balance the heaps to maintain the size condition
            if (balance < 0) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (balance > 0) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            
            // Remove elements that should be discarded
            while (!maxHeap.empty() && mp[maxHeap.top()]) {
                mp[maxHeap.top()]--;
                maxHeap.pop();
            }
            while (!minHeap.empty() && mp[minHeap.top()]) {
                mp[minHeap.top()]--;
                minHeap.pop();
            }
        }

        // Add the final median after the loop finishes
        if (k & 1) {
            medians.push_back(maxHeap.top() * 1.0);
        } else {
            medians.push_back(((double)maxHeap.top() + (double)minHeap.top()) / 2.0);
        }

        return medians;
    }
};
