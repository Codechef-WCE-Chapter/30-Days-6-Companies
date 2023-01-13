class Solution {
public:
    bool dfs(int bob,int parent,int steps,vector<int>& dist,vector<int> adj[]){
        if(bob==0){
            dist[bob]=steps;
            return true;
        }
        dist[bob]=steps;
        for(auto i:adj[bob]){
            if(i!=parent){
                if(dfs(i,bob,steps+1,dist,adj)){
                    return true;
                }
            }
        }
        dist[bob]=1e5;
        return false;
    }
    int maximumProfit(int node,int parent,int steps,vector<int>& amount,vector<int>& distFromBob,vector<int> adj[]){
        int ans=0;
        if(steps==distFromBob[node]){
            ans+=amount[node]/2;
        }
        if(steps<distFromBob[node]){
            ans+=amount[node];
        }
        int maxi=-1e9;
        for(auto i:adj[node]){
            if(i!=parent){
                maxi=max(maxi,maximumProfit(i,node,steps+1,amount,distFromBob,adj));
            }
        }
        return maxi==-1e9?ans:ans+maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int> adj[n];
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> distFromBob(n,1e5);
        dfs(bob,-1,0,distFromBob,adj);
        return maximumProfit(0,-1,0,amount,distFromBob,adj);
    }
};