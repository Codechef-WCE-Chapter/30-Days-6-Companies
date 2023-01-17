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
#define inf 11111111111
using namespace std;
// Function to calculate distance
float distance1(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
int numberOfBoomerangs1(vector<vector<int>> &pts)
{
    int n = pts.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                vector<int> pt1 = pts[i];
                vector<int> pt2 = pts[j];
                double dit1 = distance1(pt1[0], pt1[1], pt2[0], pt2[1]);
                for (int k = 0; k < n; k++)
                {
                    if (k != j)
                    {
                        vector<int> pt3 = pts[i];
                        vector<int> pt4 = pts[k];
                        double dit2 = distance1(pt3[0], pt3[1], pt4[0], pt4[1]);
                        if (dit1 == dit2)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

// /---------------------meth2-------------TC:O(n2)+SC:O(n)
double distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    // return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
    return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 1.0;
}

// /----TC:O(n2)+SC:O(n)----
int numberOfBoomerangs2(vector<vector<int>> &pts)
{
    int n = pts.size();
    int ans = 0;
    unordered_map<double, int> distMp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double dist = distance(pts[i][0], pts[i][1], pts[j][0], pts[j][1]);
                distMp[dist]++;
            }
        }
        for (auto val : distMp)
        {
            if (val.second >= 2)
                ans += (val.second) * (val.second - 1);
            // cout << "ans:" << ans << endl;
        }
        distMp.clear();
    }
    // for (auto val : distMp)
    // {
    //     cout << val.first << "  ->" << val.second << endl;
    // }

    return ans;
}

int main()
{
    vector<vector<int>> points{{0, 0}, {1, 0}, {2, 0}};
    cout << numberOfBoomerangs2(points) << endl;
}