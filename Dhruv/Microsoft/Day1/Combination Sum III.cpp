class Solution {
public:
    void CombinationSum(int ind, vector<int> &ds, vector<vector<int>> &ans, int target, int k, int n){
        if(ds.size()==k){
            if(target==0){
                ans.push_back(ds);
                return;
            }
        }
        for(int i=ind;i<=9;i++){
            if(ds.size()>=k && target!=0) break;
            if(i>target) break;
            ds.push_back(i);
            CombinationSum(i+1, ds, ans, target-i, k, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        if(n<k){
            return ans;
        }
        CombinationSum(1, ds, ans, n, k, n);
        return ans;
    }
};