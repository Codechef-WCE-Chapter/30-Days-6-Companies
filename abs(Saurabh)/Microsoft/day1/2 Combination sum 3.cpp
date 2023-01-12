class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>>result;
        vector<int>solution;
        int sum=0;

        getResult(result,solution,0,1,sum,k,n);
        return result;
    }
    
    void getResult(vector<vector<int>>&result,vector<int>&solution,int num,int last,int sum,int k,int n)
    {
        if(num==k && sum==n){
            result.push_back(solution);
            return;
        }
        
        for(int i=last;i<=9 && num<k;++i)
        {
            if(sum+i>n)
            {
                break;
            }
            solution.push_back(i);
            getResult(result,solution,num+1,i+1,sum+i,k,n);
            solution.pop_back();
        }
    }
};