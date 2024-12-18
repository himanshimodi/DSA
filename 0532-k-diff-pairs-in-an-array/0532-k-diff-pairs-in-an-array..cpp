class Solution {
public:
    int bs(vector<int> &a, int s, int e, int k){
        int mid= s+(e-s)/2;

        while(s<=e){
            if(a[mid]==k){
                return mid;
            }
            else if(k>a[mid]){
                //right search
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid= s+(e-s)/2;
        }
        return -1;
    }

    int findPairs(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        set<pair<int,int>> ans;

        for(int i=0; i<a.size(); i++){
            if(bs(a,i+1,a.size()-1,a[i]+k) !=-1){ // =-1 when our element is not found
                ans.insert({a[i],a[i]+k});
            }
        }
        return ans.size();
    }
};