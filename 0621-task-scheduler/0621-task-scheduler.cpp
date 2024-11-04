class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(auto task : tasks){
            freq[task]++;
        }

        priority_queue<pair<int,char>, vector<pair<int,char>>> maxHeap;

        for(auto i : freq){
            maxHeap.push({i.second, i.first});
        }

        int time=0;

        while(!maxHeap.empty()){
            int cycle = n+1;
            vector<pair<int,char>>temp;
            while(cycle>0 && !maxHeap.empty()){
                auto [freq,task] = maxHeap.top();
                maxHeap.pop();
                freq--;
                time++;
                cycle--;

                //push remaining tasks
                temp.push_back({freq,task});
            }

            for(auto leftTasks : temp){
                if(leftTasks.first >0){
                    maxHeap.push(leftTasks);
                }
            }

            if(!maxHeap.empty()){
                time+=cycle;
            }
        }
        return time;
    }
};