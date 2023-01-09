// Backtracking used

class Solution {
public:

    void find(int k,int n, vector <int> &v, int i){
        if(n==0 && k==0){
        ans.push_back(v);
        return;
    }
    if(n==0){
        return;
    }
    if(k==0){
        return;
    }
    if(k>9){
        return;
    }
        for(int j = i; j<=9; j++){
            v.push_back(j);
            k--;
            find(k,n-j,v,j+1);
            k++;
            v.pop_back();
        }
    }

    vector <vector <int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> v;
        find(k,n,v,1);
        return ans;
    }
};