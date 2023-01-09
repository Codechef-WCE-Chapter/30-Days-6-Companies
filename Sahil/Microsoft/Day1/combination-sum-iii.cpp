class Solution {
public:
    vector<vector<int>> ans;
    int sum(vector<int> &cur){
        int s = 0;
        for(auto x:cur){
            s += x;
        }
        return s;
    }
    void fun(int n,vector<int>&cur,int k , int digit){
        if(k==0){
            if(sum(cur)==n){
                ans.push_back(cur);
            }
        }else{
            if(digit>9){
                return;
            }
            cur.push_back(digit);
            fun(n,cur,k-1,digit+1);
            cur.pop_back();
            fun(n,cur,k,digit+1);
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        fun(n,cur,k,1);
        return ans;
    }
};