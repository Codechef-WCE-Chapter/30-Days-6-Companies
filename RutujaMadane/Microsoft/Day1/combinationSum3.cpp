class Solution {
    private:
    void func(int start,int sum,int n,vector<vector<int>>& ans,vector<int>& result,int m){
        if(sum==n&&m==0){
            ans.push_back(result);
        }
        if(sum>n){
            result;
        }
        for(int i=start;i<=9;i++){
            if(i>n){
                break;
            }
        result.push_back(i);
        func(i+1,sum+i,n,ans,result,m-1);
       result.pop_back();
    }
    }
public:
    vector<vector<int>> combinationSum3(int m, int n) {
        vector<int>result;
        vector<vector<int>>ans;
        func(1,0,n,ans,result,m);
        return ans;
    }
    
};
