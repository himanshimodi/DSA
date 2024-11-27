class Info {
    public:
    int data;
    int rIndex;
    int cIndex;

    Info(int a, int b, int c){
        data = a;
        rIndex = b;
        cIndex = c;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data; // this is min heap ka comparator
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info* , vector<Info*>, compare> pq;
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        //process first k elements
        for(int row =0; row<nums.size(); row++){
            int ele = nums[row][0];
            Info * temp = new Info(ele,row,0);
            pq.push (temp);
            maxi = max(maxi,ele);
            mini = min(mini,ele);
        }   

        int ansStart = mini;
        int ansEnd = maxi;

        //main logic
        while(!pq.empty()){
            //front nikalo
            Info * front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;

            //dont forget, most imp
            mini = frontData;

            //ans update
            if((maxi-mini)< (ansEnd-ansStart)){
                //found a new smaller diff
                ansStart = mini;
                ansEnd = maxi;
            }
            //aage element h toh insert kro
            int currTotalCol = nums[front_rIndex].size();
            if(front_cIndex+1 < currTotalCol){
                int ele = nums[front_rIndex][front_cIndex +1];
                Info * temp = new Info(ele, front_rIndex, front_cIndex+1);
                pq.push(temp);
                maxi = max(maxi,ele);
                mini = min(mini,ele);
            }
            else{
                break;
            }

        }
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};