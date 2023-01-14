class Solution {
    int mod = 1e9+7;
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long int>>>adj(n);
        for(int i = 0;i<roads.size();i++){
            adj[roads[i][0]].push_back(make_pair(roads[i][1],roads[i][2]));
            adj[roads[i][1]].push_back(make_pair(roads[i][0],roads[i][2]));
        }
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        vector<long long int>dist(n);
        vector<long long int>path(n,0);
        for(int i = 0;i<n;i++){
            dist[i] = 1e15;
        }
        dist[0] = 0;
        path[0] = 1;
        pq.push({0,0});
        int maxi = 0;
        while(!pq.empty()){
            long long int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long int time = it.second;
                int adjNode = it.first;
                
                 if(dist[adjNode]>d+time){
                    pq.push({d+time,adjNode});
                    dist[adjNode] = d+time;
                    path[adjNode] = path[node]%mod;
                }
                else if(dist[adjNode] == d+time){
                    path[adjNode] = (path[adjNode] + path[node])%mod;
                }
            }
        }
        return path[n-1];
    }
};