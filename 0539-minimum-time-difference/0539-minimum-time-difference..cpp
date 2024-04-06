class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        //step 1 :convert time string into minutes integer value
        vector<int> minutes;

        for(int i=0; i<timePoints.size();i++){
            string curr= timePoints[i];

            int hours = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        //step 2: sort, to reduce the number of comparisons
        sort(minutes.begin(), minutes.end());

        //step 3: calculate difference and minimum difference 
        int mini=INT_MAX;
        int n = minutes.size();

        for(int i=0; i<n-1;  i++){ 
        // n-1 is to prevent going out of bound i.e, out of the array 
            int diff = minutes[i+1]-minutes[i];
            mini = min(diff, mini);
        }

        //THIS IS THE GAME: finding circular difference here(24hrs=1440minutes)
        int lastDiff = (minutes[0]+1440)-minutes[n-1];
        mini = min(lastDiff, mini);

        return mini;
    }
};