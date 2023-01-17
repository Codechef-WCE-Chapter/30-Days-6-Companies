// https: // leetcode.com/problems/max-points-on-a-line/description/

// Given an array of points where points[i] = [ xi, yi ] represents a point on the X - Y plane, return the maximum number of points that lie on the same straight line.

// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3

// run three for loops i and j two points
//  now run again loop execpet for i and j and check if slope same

// i j k
// slope(i,j)==slope(i,k)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &v)
    {

        int n = v.size();
        if (n <= 2)
            return n;

        int cnt = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int total = 2;
                for (int k = 0; k < n; k++)
                {
                    if (k != i and k != j)
                    {

                        //v[i],v[j],v[k]

                        int mul1 = (v[j][1] - v[i][1]) * (v[k][0] - v[i][0]);
                        int mul2 = (v[j][0] - v[i][0]) * (v[k][1] - v[i][1]);

                        if (mul1 == mul2)
                            total++;
                    }
                }
                cnt = max(cnt, total);
            }
        }
        return cnt;
    }
};

int32_t main()
{

    return 0;
}