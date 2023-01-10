class Solution {
public:
    set<vector<int>>ans;
    void combine(int a,vector<int>&visited,vector<int>&curr,int k,int n)
    {
        if(curr.size()==k)
        {
            if(a==n)
            {
                // sort(curr.begin(),curr.end());
                vector<int>T=curr;
                sort(T.begin(),T.end());
                ans.insert(T);

            }
            return ;
        }
        for(int i=1;i<=9;i++)
        {
            if(!visited[i] and a+i<=n)
            {
                visited[i]=true;
                curr.push_back(i);
                a+=i;
                combine(a,visited,curr,k,n);
                curr.pop_back();
                a-=i;
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>visited(10,0);
        vector<int>curr;
        combine(0,visited,curr,k,n);
        vector<vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};