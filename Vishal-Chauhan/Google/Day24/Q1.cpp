#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int INF = 1000000000;
    int networkDelayTime(vector<vector<int>> &times, int V, int S)
    {

        vector<vector<int>> adj[V + 1];
        for (auto a : times)
        {
            adj[a[0]].push_back({a[1], a[2]});
        }

        vector<int> dist(V + 1, INF);
        vector<bool> vis(V + 1, 0);
        dist[0] = 0;
        dist[S] = 0;
        set<pair<int, int>> st;
        st.insert({0, S});
        while (st.size() > 0)
        {

            pair<int, int> node = *st.begin();
            int v_dist = node.first;
            st.erase(st.begin());
            if (vis[node.second])
                continue;
            vis[node.second] = 1;

            for (auto child : adj[node.second])
            {
                if (v_dist + child[1] < dist[child[0]])
                {
                    dist[child[0]] = v_dist + child[1];
                    st.insert({dist[child[0]], child[0]});
                }
            }
        }
        int sum = 0;
        for (auto a : dist)
        {
            if (a == 1000000000)
                return -1;
            sum = max(sum, a);
        }
        return sum;
    }
};
int main()
{
}