class Solution {
public:

    void getAns(vector<vector<int>>&ans,vector<int>&t, int k, int n, int s){
        
        if(n==0 && k==0){
            ans.push_back(t);
        }
        for(int i = s;i<=9;i++){
            if(k<0)return;
            t.push_back(i);
            getAns(ans,t,k-1,n-i,i+1);
            t.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>t;
        getAns(ans,t,k,n,1);
        return ans;
    }
};