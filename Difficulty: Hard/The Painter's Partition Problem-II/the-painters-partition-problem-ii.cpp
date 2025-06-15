// User function template for C++

class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int k, int mid){
        int painter =1;
        int boardlen=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid){
                return false;
            }
            
            if(boardlen+arr[i]<=mid){
                boardlen+=arr[i];
            }
            else{
                painter++;
                if(painter>k){
                    return false;
                }
                boardlen=0;
                boardlen+=arr[i];
            }
        }
        return true;
    } 
  
    int minTime(vector<int>& arr, int k) {
        // code here
        
        // if(k>arr.size()){
        //     return -1;
        // }
        
        int s=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int e = sum;
        int mid = s+(e-s)/2;
        int ans =-1;
        
        while(s<=e){
            if(isPossible(arr,k,mid)==true){
                ans= mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        // return minimum time
        return ans;
    }
};