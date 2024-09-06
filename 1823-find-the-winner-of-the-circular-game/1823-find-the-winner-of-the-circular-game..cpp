class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        while(q.size()>1){
            //stimulate the game
            for(int i=1; i<k; i++){
                auto player = q.front();
                q.pop();

                //not eliminated
                q.push(player);
            }
            //kth player must be eliminated
            q.pop();
        }
        return q.front();
    }
};