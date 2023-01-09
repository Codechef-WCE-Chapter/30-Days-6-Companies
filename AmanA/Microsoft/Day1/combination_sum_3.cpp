//https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void combination(vector<vector<int>>& ans,vector<int>& arr,int index,int start,int k, int n,int sum){
        if(n==sum && k==0){
            ans.push_back(arr);
            return;
        }
        else{
            
            if(sum>n || (k==0 && sum<n)) return;
            else{
                for(int i = start;i<=9;i++){
                    arr[index] = i;
                    // sum+=arr[index];
                    combination(ans,arr,index+1,i+1,k-1,n,sum+arr[index]);
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k>n) return ans;
        vector<int> arr(k,0);
        int sum = 0;
        combination(ans,arr,0,1,k,n,sum);
        return ans;
    }
};
