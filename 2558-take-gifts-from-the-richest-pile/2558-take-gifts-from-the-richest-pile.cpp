class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        long long ans = 0;
        for(auto u: gifts){
            ans += u;
            q.push(u);
        }

        while(k--){
            int topElement = q.top();
            q.pop();
            q.push(sqrt(topElement));
            ans -= (topElement - sqrt(topElement));
        }
        return ans;
    }
};