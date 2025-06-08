class Solution {
public:
    bool caneatall(vector<int>&piles,int k, int h){
        long long hours =0;
        for(int pile : piles){
            hours+=(pile+k-1)/k;
        }
        if(hours<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());
        int result = high;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(caneatall(piles,mid,h)){
                result = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};