class Solution {
public:
    void calculate(vector<vector<int>> &ans, vector<int>cur, int n, int k, int start){
        if(n==0 and k==0)
        { 
        ans.push_back(cur); 
        return;
        }
    if(k==0)
    {
        return;
    }
    for(int i=start;i<10;i++){
        cur.push_back(i); 
        calculate(ans, cur, n-i, k-1, i+1);
        cur.pop_back(); 
    }
    return; 
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector<int>> ans;
        vector<int>cur;
        calculate(ans, cur, n, k, 1);

        return ans;
    }
};
    
