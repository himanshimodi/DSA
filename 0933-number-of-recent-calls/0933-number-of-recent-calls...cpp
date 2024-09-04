class RecentCounter {
    queue<int>q;
public:
      
    int ping(int t) {
        //step1:
        q.push(t);

        //step2:pop invalid older req, older than t-3000
        while(!q.empty() && q.front()<(t-3000)){
            q.pop();
        }

        //step3:
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */