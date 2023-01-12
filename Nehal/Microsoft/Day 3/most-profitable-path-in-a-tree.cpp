class Solution
{
public:
    bool DFS(int src, int time, unordered_map<int, int> &path, vector<bool> &visited, vector<vector<int>> &graph)
    {
        path[src] = time;
        visited[src] = true;
        if (src == 0)
        {
            return true;
        }
        for (auto adj : graph[src])
        {
            if (!visited[adj])
            {
                if (DFS(adj, time + 1, path, visited, graph))
                {
                    return true;
                }
            }
        }
        path.erase(src);
        return false;
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        // Find the path taken by bob to reach zero along with the time at which bob visited that node
        unordered_map<int, int> path;
        vector<bool> visited(n, false);
        DFS(bob, 0, path, visited, graph);

        // Push {src, time, income}
        queue<vector<int>> q;
        q.push({0, 0, 0});
        visited.assign(n, false);

        int ans = INT_MIN;
        while (!q.empty())
        {
            int src = q.front()[0], time = q.front()[1], income = q.front()[2];
            q.pop();
            visited[src] = true;

            // If bob didn't visit this node
            if (path.find(src) == path.end())
            {
                income += amount[src];
            }
            else
            {
                // Alice visits it first
                if (time < path[src])
                {
                    income += amount[src];
                }
                // Both visit at the same time
                else if (time == path[src])
                {
                    income += (amount[src] / 2);
                }
            }

            // Updating when it is leaf
            if (graph[src].size() == 1 && src != 0)
            {
                ans = max(ans, income);
            }
            // Exploring adjacent vertices
            for (auto adj : graph[src])
            {
                if (!visited[adj])
                {
                    q.push({adj, time + 1, income});
                }
            }
        }

        return ans;
    }
};