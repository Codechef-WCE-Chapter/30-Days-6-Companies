class Solution {
public:
    void maxArea(int node, vector<int> adj[], vector<int> &vis, int &ans) {
        vis[node] = 1;
        ans++;
        // cout << node << " ";
        for(auto i : adj[node]) {
            if(!vis[i]) {
                maxArea(i, adj, vis, ans);  
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> adj[n*m + 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                if(i != 0) {
                    if(grid[i - 1][j] == 1) {
                        adj[i*m + j + 1].push_back((i - 1)*m + j + 1);
                        adj[(i - 1)*m + j + 1].push_back(i*m + j + 1);
                    }
                }
                if(j != 0) {
                    if(grid[i][j - 1] == 1) {
                        adj[i*m + j + 1].push_back(i*m + j);
                        adj[i*m + j].push_back(i*m + j + 1);
                    }
                }
                if(i != n - 1) {
                    if(grid[i + 1][j] == 1) {
                        adj[i*m + j + 1].push_back((i + 1)*m + j + 1);
                        adj[(i + 1)*m + j + 1].push_back(i*m + j + 1);
                    }
                }
                if(j != m - 1) {
                    if(grid[i][j + 1] == 1) {
                        adj[i*m + j + 1].push_back(i*m + j + 2);
                        adj[i*m + j + 2].push_back(i*m + j + 1);
                    }
                }
                }
            }
        }
        vector<int> vis(n*m + 1, 0);
        int maxm = 0;
        for(int i = 1; i <= n*m; i++) {
            int f = (i - 1) / m;
            int s = i - (m * f) - 1;
            if(grid[f][s] == 1) {
            if(!vis[i]) {
                int curr = 0;
                maxArea(i, adj, vis, curr);
                maxm = max(maxm, curr);
                // cout << endl;
            }
            }
        }
        return maxm;
    }
};
