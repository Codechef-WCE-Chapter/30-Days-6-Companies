#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
// #define MOD 1000000007

class Solution{
    int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads){
        vector<pair<int, int>> ADJ[n];
        for(auto road : roads){
            ADJ[road[0]].push_back({road[1], road[2]});
            ADJ[road[1]].push_back({road[0], road[2]});
        }

        // Priority Queue for Dijkstra's algo
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        PQ.push({0, 0});    // Pushing the source node

        // Distance and Ways array
        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // Dijkstra
        while(!PQ.empty()){
            int distance = PQ.top().first, node = PQ.top().second;
            PQ.pop();

            for(auto child : ADJ[node]){
                int adjNode = child.first;
                int adjDist = child.second;

                // Arriving for the first time
                if(distance + adjDist < dist[adjNode]){
                    dist[adjNode] = distance + adjDist;
                    ways[adjNode] = ways[node];

                    PQ.push({dist[adjNode], adjNode});
                }
                // Arriving for the not first time with same distance
                else if(distance + adjDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] +  ways[node])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};

void solve(){
    
    
    return;
}

int main(){
    fastIO
    ll t;
    cin>>t;
           
    while(t--){
        solve();
    }
              
    return 0;
}
