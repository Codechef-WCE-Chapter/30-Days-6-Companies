class Solution{
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int start){
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(n < 0 || temp.size() > k){
            return;
        }
        for(int i = start; i <= 9; i++){
            temp.push_back(i);
            solve(ans, temp, k, n - i, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, temp, k, n, 1);

        return ans;
    }
};
