#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void combinations(int k, int n, int val, vector<int> &v, vector<vector<int>> &v1){
        if(n==0){
            if(k==0){
                v1.push_back(v);
                return;
            }
            else{
                return;
            }
        }
        if(val>9){
            return;
        }
        if(n-val>=0){
            v.push_back(val);
            combinations(k-1, n-val, val+1, v, v1);
            v.pop_back();
        }
        combinations(k, n, val+1, v, v1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n){
       vector<vector<int>> ans;
       vector<int> v;
       combinations(k, n, 1, v, ans);
       return ans; 
    }
};