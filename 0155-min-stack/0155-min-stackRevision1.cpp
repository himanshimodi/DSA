class MinStack {
public:
    MinStack() {
        
    }
    vector<pair<int,int>>ans;
    void push(int val) {
        if(ans.empty()){
            ans.push_back({val,val});
            return;
        }
        else{
            int min = val;
            if(ans.back().second < min){
                min = ans.back().second;
            }
            ans.push_back({val,min});
        }
    }
    
    void pop() {
        ans.pop_back();
    }
    
    int top() {
        return ans.back().first;
    }
    
    int getMin() {
        return ans.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */