//216.Combination Sum III

class Solution {
public:
    void solve(int i,int currsum,vector<int>& temp,vector<vector<int>>& ans,int k,int n)
    {
        if(currsum>n || temp.size()>k)
            return;
        if(currsum==n && temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int e=i;e<=9;++e)
        {
           temp.push_back(e);
           currsum+=e;
           solve(e+1,currsum,temp,ans,k,n);
           currsum-=e;
           temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,0,temp,ans,k,n);
        return ans;
    }
};
