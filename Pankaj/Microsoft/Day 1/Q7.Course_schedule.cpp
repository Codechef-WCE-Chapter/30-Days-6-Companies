//Microsoft: Q7.Course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto& i:prerequisites){
            int u=i[1];
            int v=i[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return res.size()==n;
    }
};