//216. Combination Sum III
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int last,int sum,int k,int n,vector<int>& ds){
        if(k==0){
            if(sum==n){
                ans.push_back(ds);
            }
            return;
        }
        for(int num=last+1;num<=9;num++){
            if(sum+num<=n){
                ds.push_back(num);
                solve(num,sum+num,k-1,n,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        solve(0,0,k,n,ds);
        return ans;
    }
};