class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        //condition 1: choose A such that  its upper or left to B
        //condition 2: there should be no point betw x1 and x2 & same for y

         int ans = 0;
        sort(points.rbegin(), points.rend());  // sort by x descending

        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 <= x2 && y1 >= y2 && (x1 < x2 || y1 > y2)) {
                    bool valid = true;
                    for (int k = 0; k < points.size(); k++) {
                        if (k == i || k == j) continue;
                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if (x1 <= x3 && x3 <= x2 && y1 >= y3 && y3 >= y2) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) ans++;
                }
            }
        }
        return ans;
    }
};