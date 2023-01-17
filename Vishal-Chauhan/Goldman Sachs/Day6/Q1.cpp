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

int max(int a, int b)
{
    return a > b ? a : b;
}
// --------------method1------------
int maxPoints1(vector<vector<int>> &pts)
{

    int n = pts.size();
    int ans = 0;
    if (n < 3)
        return n;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = 2;
            for (int k = 0; k < n; k++)
            {

                if (k != i && k != j)
                {
                    //    vector<int> pt1=pts[i];
                    //    vector<int> pt2=pts[j];
                    //    vector<int> pt3=pts[k];
                    //    int x1=pt1[0],x2=pt2[0],x3=pt3[0];
                    //    int y1=pt1[1],y2=pt2[1],y3=pt3[1];
                    //    if((y1-y2)*(x2-x3)==(y2-y3)*((x1-x2)))temp++;
                    if ((pts[i][1] - pts[j][1]) * (pts[j][0] - pts[k][0]) == (pts[j][1] - pts[k][1]) * ((pts[i][0] - pts[j][0])))
                        temp++;
                }
            }
            ans = max(ans, temp);
        }
    }

    return ans;
}

// meth2---------------
int maxPoints2(vector<vector<int>> &pts)
{

    int n = pts.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<double, int> mp;
        mp.clear();
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double slope = 0;
                vector<int> pt1 = pts[i];
                vector<int> pt2 = pts[j];
                if ((pt2[0] - pt1[0]) != 0)
                {
                    slope = (pt2[1] - pt1[1]) / (pt2[0] - pt1[0]);
                    mp[slope]++;
                }
                else
                {
                    cout << "elde block\n";
                    mp[inf]++;
                }
            }
        }
        for (auto val : mp)
        {
            {
                cout << val.first << "->  " << val.second << endl;
                ans = max(ans, val.second + 1);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> pts{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << "ans:" << maxPoints1(pts) << endl;
}