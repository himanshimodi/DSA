class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;

        int pairs = n/2;
        for(int i=1;i<=pairs;i++){
            ans.push_back(i);
            ans.push_back(-i);
        }

        //if n is odd also append zero
        if(n%2 ==1){
            ans.push_back(0);
        }
        return ans;
    }
};