// User function Template for C

bool isPossible(int arr[], int n, int k, int mid){
    int student=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){ //first book ka pages ke more than mid
            return false;
        }
        
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            student++;
            if(student>k){
                return false;
            }
            pageSum=0;
            pageSum+=arr[i];
        }
    }
    return true;
}



int findPages(int arr[], int n, int k) {
    // code here
    
    if(k>n){
        return -1;
    }
    
    int ans=-1;
    int s=0;
    int sum=0;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e =sum;
    int mid = s+(e-s)/2;
    
    while(s<=e){
        if(isPossible(arr,n,k,mid)==true){
            ans= mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}