#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dis(n, vector<int>(n, int(1e6)));
        for (int i = 0; i < n; i++) // Initialising distance needed to move from a node to itself = 0
            dis[i][i] = 0;

        for (auto edge : edges)
        { // Forming the edges given between nodes
            int u = edge[0], v = edge[1], w = edge[2];
            dis[u][v] = dis[v][u] = w;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dis[i][j] > dis[i][k] + dis[k][j]) // applying Floyd Warshall
                        dis[i][j] = dis[i][k] + dis[k][j]; // when the distance to travel from a node to another is smaller when k is an intermediate node

        int ans = 0, ans_count = n;
        for (int i = 0; i < n; i++)
        { // traversing for each node
            int count = 0;
            for (int j = 0; j < n; j++)             // traversing each jth node from ith node
                if (dis[i][j] <= distanceThreshold) // if distance is less than threshold distance, increment count
                    count++;

            if (count <= ans_count)
            { // if count is less tha or equal to min count found, change the values
                ans_count = count;
                ans = i;
            }
        }

        return ans; // return answer
    }
};

int main()
{
    Solution s;
    cout << s.findTheCity(5, {{1, 2, 5}, {2, 3, 8}, 1, 3, 7}, 15) << endl;
}