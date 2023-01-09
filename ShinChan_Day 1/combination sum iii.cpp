class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int> &v, int k, int n, int ind, vector<int> nums){
        
        if(n<0 ) return;
        if(n==0){
            if(k==0)
            ans.push_back(nums);
            return;
        } 
        if(ind<0) return;

      
        if(v[ind]<=n){
            nums.push_back(v[ind]);
            rec( v, k-1, n-v[ind], ind-1, nums);
            nums.pop_back();
        }
        rec( v, k, n, ind-1, nums);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<int> nums;
        for(int i=1; i<=9; i++){
            v.push_back(i);
        }
         rec( v, k, n, v.size(), nums);
         return ans;
    }
};