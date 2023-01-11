class Solution {
public:
   void Answer(vector<vector<int>>&ans,vector<int>&temp,int n,int k,int index)
   {
       if(k==0&&n==0)
       {
           ans.push_back(temp);
       }
       for(int i=index;i<=9;i++)
       {
           if(k<0)return;
          temp.push_back(i);
          Answer(ans,temp,n-i,k-1,i+1);//why it dosent work when we write index+1
          temp.pop_back();   
       }
   }
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>>ans;
      vector<int>temp;
      Answer(ans,temp,n,k,1);
      return ans;  
    }
};