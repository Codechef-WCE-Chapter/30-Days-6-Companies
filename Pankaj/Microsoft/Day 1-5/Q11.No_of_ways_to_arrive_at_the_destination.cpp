//Microsoft: Q.11.Number of ways to arrive at a Destination
#define ll long long int
const int MOD=1e9+7;
const int N=1e18;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto it:roads){
            ll u=it[0];
            ll v=it[1];
            ll w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<ll> noWays(n,0);
        vector<ll> dist(n,LONG_MAX);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        noWays[0]=1;
        dist[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            ll node=it.second;
            ll dis=it.first;
            pq.pop();
            for(auto i:adj[node]){
                if(dist[i.first]>dis+i.second){
                    dist[i.first]=(dis+i.second);
                    noWays[i.first]=noWays[node];
                    pq.push({dist[i.first],i.first});
                }
                else if(dist[i.first]==dis+i.second){
                    noWays[i.first]=(noWays[i.first]+noWays[node])%MOD;
                }
            }
        }
        return noWays[n-1];
    }
};