#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int>> hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << s.calculateMinimumHP(dungeon) << endl;
}