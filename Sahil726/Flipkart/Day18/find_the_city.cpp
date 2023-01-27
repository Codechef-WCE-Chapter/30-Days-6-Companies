int dijkistra(vector<int> &vis, int start, vector<vector<pair<int, int>>> &adj, int thresh, int n)
{
    vis[start] = 0;
    stack<pair<int, int>> st;
    st.push({start, 0});
    while (!st.empty())
    {
        int vertex = st.top().first;
        int distance = st.top().second;
        st.pop();
        for (auto it : adj[vertex])
        {
            int node = it.first;
            int ndis = it.second;
            if (distance + ndis < vis[node])
            {
                vis[node] = distance + ndis;
                st.push({node, distance + ndis});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] <= thresh)
            cnt++;
        cout << vis[i] << " ";
    }
    cout << endl;
    return cnt - 1;
}
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int maxi = INT_MAX;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n, INT_MAX);
            int mini = dijkistra(visited, i, adj, distanceThreshold, n);
            if (maxi >= mini)
            {
                maxi = mini;
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
