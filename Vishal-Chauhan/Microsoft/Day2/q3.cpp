#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_set>
#define ll long long int
using namespace std;
bool isRectangleCover(vector<vector<int>> &rectangles)
{
    unordered_set<string> points;
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    int area = 0;
    for (auto &rec : rectangles)
    {
        minX = min(minX, rec[0]);
        minY = min(minY, rec[1]);
        maxX = max(maxX, rec[2]);
        maxY = max(maxY, rec[3]);
        area += (rec[2] - rec[0]) * (rec[3] - rec[1]);

        string p1 = to_string(rec[0]) + " " + to_string(rec[1]);
        string p2 = to_string(rec[0]) + " " + to_string(rec[3]);
        string p3 = to_string(rec[2]) + " " + to_string(rec[3]);
        string p4 = to_string(rec[2]) + " " + to_string(rec[1]);

        if (!points.insert(p1).second)
            points.erase(p1);
        if (!points.insert(p2).second)
            points.erase(p2);
        if (!points.insert(p3).second)
            points.erase(p3);
        if (!points.insert(p4).second)
            points.erase(p4);
    }

    if (points.size() != 4 || !points.count(to_string(minX) + " " + to_string(minY)) || !points.count(to_string(minX) + " " + to_string(maxY)) ||
        !points.count(to_string(maxX) + " " + to_string(minY)) || !points.count(to_string(maxX) + " " + to_string(maxY)))
    {
        return false;
    }

    return area == (maxX - minX) * (maxY - minY);
}

int main()
{
    vector<vector<int>> CoorDinates{{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}};
    bool ans = isRectangleCover(CoorDinates);
    cout << "isRect:" << ans << endl;

    vector<vector<int>> rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    cout << "isRect2:" << isRectangleCover(rectangles) << endl;
}