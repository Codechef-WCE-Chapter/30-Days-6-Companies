#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
bool canFinish(int numC, vector<vector<int>> &pre)
{
    set<int> a, b;
    for (auto val : pre)
    {
        if (a.find(val[0]) == a.end())
        {
            a.insert(val[0]);
        }
        else
        {
            return false;
        }
        if (b.find(val[1]) == b.end())
        {
            b.insert(val[1]);
        }
        else
            return false;
    }
    if (pre.size() == 0)
        return true;
    if (a.size() + b.size() == numC)
        return true;
    else
        return false;
}
// meth2---------------------
bool dfs(int curr, vector<int> &vis, vector<vector<int>> &adj, vector<int> &rec)
{
    vis[curr] = 1;
    for (auto itr : adj[curr])
    {
        if (vis[itr] == 0)
        {
            if (rec[itr] == 1)
                continue;
            if (!dfs(itr, vis, adj, rec))
            {
                return false;
            }
        }
        else
            return false;
    }
    rec[curr] = 1;
    vis[curr] = 0;
    return true;
}
bool canFinish(int nc, vector<vector<int>> &p)
{
    vector<int> vis(nc, 0), rec(nc, 0);
    // rec -> 0 (not traversed), 1 (safe/ no need to traverse), 2 (loop)
    // vis stores visited record only during a single traversaL and gets reset every time
    // rec store if the node was traversed in previous iterations is does not contain a loop

    // rec is used to reduce time complexity from O(N^2) to O(N)
    // vis is used to find loop in a single traversal

    vector<vector<int>> adj(nc);
    for (auto itr : p)
    {
        adj[itr[1]].push_back(itr[0]);
    }
    bool res = true;
    for (int i = 0; i < nc; i++)
    {
        if (vis[i] == 0 && rec[i] == 0)
        {
            res = dfs(i, vis, adj, rec);
            if (!res)
                return false;
        }
    }
    return true;
}

// --------------------------

using namespace std;
int main()
{
    int numOfC = 5;
    vector<vector<int>> preR{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    cout << canFinish(numOfC, preR) << endl;
}