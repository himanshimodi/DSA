class Solution {
public:

    // vector<int>twoPtrMethod(vector<int> & arr, int k , int x){
    //     int l=0,h=arr.size()-1;

    //     while(h-l >=k){
    //         if(x-arr[l] > arr[h]-x){
    //             l++;
    //         }
    //         else{
    //             h--;
    //         }
    //     }
    //     vector<int> ans;
    //     for(int i=l; i<=h; i++){
    //         ans.push_back(arr[i]);
    //     }
    //     return ans;
    // }

    int lowerBound(vector<int> &arr, int x){
        int s=0, e=arr.size()-1;
        int mid= s+(e-s)/2;
        int ans=e;
        while(s<=e){
            if(x<=arr[mid]){
                ans=mid;
                e=mid-1;
            }
            else if(x>arr[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid= s+(e-s)/2;
        }
        return ans;
    }

    vector<int> bs_method(vector<int>& arr, int k, int x){
        int h=lowerBound(arr,x);
        int l=h-1;

        while(k--){
            if(l<0){
                h++;
            }
            else if(h>=arr.size()){
                l--;
            }
            else if(x-arr[l]> arr[h]-x){ //comparing the difference
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int> (arr.begin() + l + 1, arr.begin() + h);
    }


    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        return bs_method(arr, k, x);      
        
        
        // vector<int> ans;
        // priority_queue<pair<int,int>> maxHeap;

        // for(int i =0;i<arr.size();i++){
        //     int diff = abs(arr[i]-x);
        //     maxHeap.push({diff,arr[i]});
        //     if(maxHeap.size()>k){
        //         maxHeap.pop();
        //     }
        // }
        // while(!maxHeap.empty() && k--){
        //     int value = maxHeap.top().second;
        //     maxHeap.pop();
        //     ans.push_back(value);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
    }
};