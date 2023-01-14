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
using namespace std;

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> arr{p1, p2, p3, p4};
        double dist1 = (pow(arr[0][0] - arr[1][0], 2) + pow(arr[0][1] - arr[1][1], 2));
        double dist2 = (pow(arr[0][0] - arr[2][0], 2) + pow(arr[0][1] - arr[2][1], 2));
        double dist3 = (pow(arr[0][0] - arr[3][0], 2) + pow(arr[0][1] - arr[3][1], 2));
        double dist4 = (pow(arr[1][0] - arr[2][0], 2) + pow(arr[1][1] - arr[2][1], 2));
        double dist5 = (pow(arr[1][0] - arr[3][0], 2) + pow(arr[1][1] - arr[3][1], 2));
        double dist6 = (pow(arr[2][0] - arr[3][0], 2) + pow(arr[2][1] - arr[3][1], 2));

        set<double> st;
        st.insert(dist1);
        st.insert(dist2);
        st.insert(dist3);
        st.insert(dist4);
        st.insert(dist5);
        st.insert(dist6);
        if (st.size() == 2 && st.find(0) == st.end())
            return true;

        return false;
    }

    bool validSquare2(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> arr{p1, p2, p3, p4};
        int flag = 0;
        for (auto val : arr)
        {
            for (auto value : arr)
            {
                vector<int> pt1 = val;
                vector<int> pt2 = value;
                int diffX = pt1[0] - pt2[0];
                int diffY = pt1[1] - pt2[1];
                // slope can be 0, 1, -1, inf
                if (diffX == 0 || diffY == 0 || (diffY / diffX) == 1 || (diffY / diffX) == -1)
                    continue;
                else
                {
                    cout << "x:" << diffX << "  y:" << diffY << endl;
                    cout << "for pt1:" << pt1[0] << " " << pt1[1] << endl;
                    cout << "for pt2:" << pt2[0] << " " << pt2[1] << endl;
                    flag++;
                    return false;
                }
            }
        }

        return true;
    }

    // [1134,-2539],[492,-1255],[-792,-1897],[-150,-3181]
};

int main()
{
    Solution s;
    vector<vector<int>> pt{{1134, -2539}, {492, -1255}, {-792, -1897}, {-150, -3181}};
    cout << "ans:" << s.validSquare(pt[0], pt[1], pt[2], pt[3]);
}