// https: // leetcode.com/problems/valid-square/description/

// Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: true

// If we calculate all distances between 4 points, 4 smaller distances should be equal (sides), and 2 larger distances should be equal too (diagonals)


#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int d(vector<int> p1, vector<int> p2)
    {
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {

        set<int> st;
        st.insert({d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4)});
        return !st.count(0) and st.size() == 2;
    }
};

int32_t main()
{

    return 0;
}