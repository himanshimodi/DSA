class Solution {
public:

    bool check(vector<int>&curr, vector<int>&prev){
        if(curr[0]>=prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2]){
            return true;
        }
        else{
            return false;
        }
    }

    //this is of LC-300 Longest Increasing Subsequence
    int solveUsingTabSO(vector<vector<int>> &cuboids) {
    int n = cuboids.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--) {
        for (int prev = curr - 1; prev >= -1; prev--) {
            int include = 0;
            if (prev == -1 || check(cuboids[curr], cuboids[prev])) {
                int heightToAdd = cuboids[curr][2];
                include = heightToAdd + nextRow[curr + 1];
            }
            int exclude = 0;
            exclude = nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        // Updating
        nextRow = currRow;
    }
    return nextRow[0]; // initial values of curr=0 and prev=-1+1=0
}

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end()); // sba kuch sort kr liya small->big

        int ans = solveUsingTabSO(cuboids);
        return ans;
    }
};