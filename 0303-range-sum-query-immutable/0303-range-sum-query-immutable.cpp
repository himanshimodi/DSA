class NumArray {
public:vector<int>prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);

        //create prefix array
        this->prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            this->prefix[i] = this->prefix[i-1] + nums[i];    
        }
    }
    
    int sumRange(int left, int right) {
        int sum =0;

        if(left !=0){
            sum+= prefix[right]- prefix[left-1];
        }
        else{
            sum+= prefix[right];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */