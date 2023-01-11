//Using Recursion

void solve(vector<vector<int>>&v,vector<int>&temp,int k,int n,int start,int sum){
    if(temp.size()==k && sum==n){
      v.push_back(temp);
      return;
    }
  //  cout<<sum<<" "<<v.size()<<endl;
    if(sum>n) return;
    for(int j=start+1;j<=9;j++){
    temp.push_back(j);
    solve(v,temp,k,n,j,sum+j);
    temp.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int>temp;
       vector<vector<int>>v;
       solve(v,temp,k,n,0,0);
       return v;
    }
};
