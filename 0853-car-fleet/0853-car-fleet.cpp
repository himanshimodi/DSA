class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<float> st;
        vector<pair<int, float>>vec; //for storing position and time saathmai

        for(int i=0; i<n; i++){
            //time = dist/speed = target-pos[i]/speed[i]
            vec.push_back({position[i], float(target-position[i])/speed[i]});
        }

        //sorting the vector
        sort(vec.begin(), vec.end());

        for( auto it: vec){
            float time = it.second;
            while(!st.empty() && (time>=st.top())){ //curr car time >= st.top->car->time
                //becomes a car fleet and now both cars have to go w the speed of the slower car
                // and both take time of the slower car to reach the destination
                st.pop();
            }
            st.push(time);
        }
        //now stack has everything in descending order
        return st.size(); //this is the number of car fleets
    }
};