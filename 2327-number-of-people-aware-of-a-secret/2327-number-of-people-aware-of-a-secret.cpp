class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9+7;
        int curr=0; //active user
        int ans= 1; //ppl who know abt secret
        queue<pair<int,int>>delayQ, forgetQ;
        delayQ.push({1,1});
        forgetQ.push({1,1});
        for(int i=1; i<=n;i++){
            //step 1
            if(!forgetQ.empty() && forgetQ.front().first + forget<=i){
                auto front = forgetQ.front();
                forgetQ.pop();
                auto no = front.second;
                ans = (ans - no + M)% M;
                curr = (curr - no + M)% M;
            }

            //step 2
            if(!delayQ.empty() && delayQ.front().first + delay <=i){
                auto front = delayQ.front();
                delayQ.pop();
                curr = curr + front.second ; 
            }

            //step 3
            if(curr > 0){
                ans = (ans + curr) % M;
                delayQ.push({i,curr});
                forgetQ.push({i,curr});
            }
        }
        return ans;
    }
};