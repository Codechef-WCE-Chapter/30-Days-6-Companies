#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<ll, ll>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty())
        {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                ll adjNode = it.first;
                ll edW = it.second;
                // this is the first time I am coming
                // with the short distance
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
int main()
{
    vector<vector<int>> roads{{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int n = 7;
    Solution s;
    cout << "total min cost path:" << s.countPaths(n, roads) << endl;
}