class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int len=0;
        for(int num :st){
            //set mai nhi mila smaller than curr number toh yaha se counting start
            if(st.find(num-1)==st.end()){    
                int currnum = num;
                int consecutivelen =1;
                //next number set mai milgya
                while(st.find(currnum+1)!=st.end()){
                    currnum++;
                    consecutivelen++;
                }
                len = max(len,consecutivelen);
            }
        }
        return len;
    }
};