class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int, int>> pq; // {fuel,position}

        while (true) {
            while (i < stations.size()) {
                // push stations within reach with my curr fuel
                if (stations[i][0] <= dist + fuel) {
                    pq.push({stations[i][1], stations[i][0]});
                } else {
                    break;
                }
                i++;
            }
            // travel with full fuel
            dist += fuel;
            fuel = 0;

            // reached
            if (dist >= target) {
                break;
            }

            // no fuel stations within reach
            if (pq.empty()) {
                stops = -1;
                break;
            }

            // refuel and re-adjust
            auto& top = pq.top();
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};