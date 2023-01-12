* Problem : https://leetcode.com/problems/course-schedule/description/

* Solution :

class Solution {
public:
    bool checkCycle(int i, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[]){
        vis[i] = 1;
        dfsVis[i] = 1;

        for(auto &ind : adj[i]){
            if(!vis[ind]){
                if(checkCycle(ind, vis, dfsVis, adj)) { return true; }
            }else if(dfsVis[ind]){ return true; }
        }

        dfsVis[i] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> vis(n ,0);
        vector<int> dfsVis(n, 0);

        for(auto &i : pre){
            int u = i[0], v = i[1];
            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(checkCycle(i, vis, dfsVis, adj)) { return false; }
            }
        }

        return true;
    }
};