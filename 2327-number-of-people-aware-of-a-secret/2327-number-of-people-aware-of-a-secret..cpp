class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9+7;
        long long curr = 0; // Use long long to handle large values
        long long ans = 1;  // Use long long for this too
        queue<pair<int, int>> delayQ, forgetQ;
        delayQ.push({1, 1});
        forgetQ.push({1, 1});
        
        for(int i = 1; i <= n; i++) {
            // Step 1: Forget people
            if(!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                auto front = forgetQ.front();
                forgetQ.pop();
                auto no = front.second;
                ans = (ans - no + M) % M;
                curr = (curr - no + M) % M;
            }

            // Step 2: Share the secret with others
            if(!delayQ.empty() && delayQ.front().first + delay <= i) {
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second) % M; // Ensure modulo here as well
            }

            // Step 3: Add new people who are aware of the secret
            if(curr > 0) {
                ans = (ans + curr) % M;
                delayQ.push({i, curr});
                forgetQ.push({i, curr});
            }
        }
        return ans;
    }
};
