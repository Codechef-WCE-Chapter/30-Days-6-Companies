class Solution {
public:
vector<int>adj[100005];
bool vis[100005];
bool dvis[100005];
    bool solve(int node )
    {
        vis[node] = 1;
        dvis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(solve(it))
                {
                    return true;
                }
            }
            else if(dvis[it])
            {
                return true;
            }

        }
        dvis[node] = 0;
        return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& p) 
    {
        if(p.size()==0)return 1;
        for(int i  = 0;i<p.size();i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
        }
      bool  x = 0;
        for(int i = 0 ;i<n;i++)
        {
            if(!vis[i])
            {
               if(solve(i )) return 0 ;
            }
        }
        return 1;
    }
};
