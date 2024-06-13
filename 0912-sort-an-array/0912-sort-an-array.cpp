class Solution {
public:
    //NORMAL MERGE SORT, TAKES SC=O(n)
    // void merge( vector<int> &v, vector<int> &temp, int s, int mid, int e){
    //     int i=s, j=mid+1, k=s;
    //     while(i<=mid && j<=e){
    //         if(v[i] < v[j]){
    //             temp[k++] = v[i++];
    //         }
    //         else{
    //             temp[k++] = v[j++];
    //         }
    //     }

    //     while( i<=mid) temp[k++] = v[i++];
    //     while( j<=e) temp[k++] = v[j++];
    //     while( s<=e){
    //         v[s] = temp[s];
    //         s++;
    //     }
    // }

    // void mergeSort(vector<int> &v, vector<int> &temp, int s, int e){
    //     if(s>=e) return;
    //     int mid = s + (e-s)/2;
    //     mergeSort(v, temp, s, mid);
    //     mergeSort(v, temp, mid+1, e);
    //     merge(v,temp,s,mid,e);
    // }

    // vector<int> sortArray(vector<int>& nums) {
    //     vector<int> temp ( nums.size(), 0);
    //     mergeSort(nums, temp, 0, nums.size()-1);
    //     return nums;
    // }

    //MERGE SORT IN PLACE, TAKES SC=O(1)
    void mergeInPlace( vector<int> &v, int s, int mid, int e){
        //size of array
        int total_len = e-s+1;

        //finding put gap, same as ceil() function
        int gap = (total_len / 2) + (total_len % 2);

        while(gap > 0){
            int i =s, j=i+gap;
            while(j<=e){
                //main condition
                if(v[i] > v[j]){
                    swap(v[i], v[j]);
                }
                i++;
                j++;
            }
            //ternary operator
            gap = gap<=1 ? 0 : (gap/2) + (gap %2);
        }
    }

    void mergeSort(vector<int> &v, int s, int e){
        if(s>=e) return;
        int mid = s + (e-s)/2;
        mergeSort(v, s, mid);
        mergeSort(v, mid+1, e);
        mergeInPlace(v,s,mid,e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};