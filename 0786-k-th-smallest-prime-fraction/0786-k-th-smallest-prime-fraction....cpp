class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>ans;
        //pair-> {numerator,denominator}
        using fracPair = pair<double, pair<int, int>>;
        priority_queue<fracPair>maxHeap;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction = (double)arr[i]/arr[j];
                maxHeap.push({fraction,{arr[i],arr[j]}});
                if(maxHeap.size()>k){
                    maxHeap.pop();//top ele ko pop kiya
                }
            }
        }
        auto topEle = maxHeap.top();
        int numerator = topEle.second.first;
        int denominator = topEle.second.second;

        ans.push_back(numerator);
        ans.push_back(denominator);
        return ans;
    }
};