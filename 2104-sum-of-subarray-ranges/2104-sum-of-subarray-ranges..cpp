class Solution {
public:
    vector<int>nextSmallerEle(vector<int> &v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=v.size()-1;i>=0;i--){
            long long curr = v[i];
            while(st.top()!=-1 && v[st.top()]>curr){
                st.pop();
            }
            //store ans and push curr
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>prevSmallerEle(vector<int> &v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=0;i<v.size();i++){
            long long curr = v[i];
            while(st.top()!=-1 && v[st.top()]>=curr){
                st.pop();
            }
            //store ans and push curr
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int> &arr){
        auto next = nextSmallerEle(arr);
        auto prev = prevSmallerEle(arr);
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++){
            long long nexti = next[i] == -1 ? arr.size() : next[i];
            long long previ = prev[i];
            long long left = i - previ;
            long long right = nexti - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    vector<int>nextGreaterEle(vector<int> &v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=v.size()-1;i>=0;i--){
            long long curr = v[i];
            while(st.top()!=-1 && v[st.top()]<curr){
                st.pop();
            }
            //store ans and push curr
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>prevGreaterEle(vector<int> &v){
        stack<int>st;
        st.push(-1);
        vector<int> ans(v.size(),-1);

        for(int i=0;i<v.size();i++){
            long long curr = v[i];
            while(st.top()!=-1 && v[st.top()]<=curr){
                st.pop();
            }
            //store ans and push curr
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int> &arr){
        auto next = nextGreaterEle(arr);
        auto prev = prevGreaterEle(arr);
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++){
            long long nexti = next[i] == -1 ? arr.size() : next[i];
            long long previ = prev[i];
            long long left = i - previ;
            long long right = nexti - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto sumOfMaximums = sumSubarrayMaxs(nums);
        auto sumOfMinimums = sumSubarrayMins(nums);
        return sumOfMaximums - sumOfMinimums;
    }
};