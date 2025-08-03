class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //max heap
        priority_queue<int>maxHeap;
        for(int i =0;i<stones.size();i++){
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size()>1){
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();
            if(a!=b){
                int diff = abs(a-b);
                maxHeap.push(diff);
            }
        }

        //matlab ab size == 1 hai heap ki
        if(maxHeap.empty()){
            return 0;
        }
        else{
            return maxHeap.top();
        }
    }
};