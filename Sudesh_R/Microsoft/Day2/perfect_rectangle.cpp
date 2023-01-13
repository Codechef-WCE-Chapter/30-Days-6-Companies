class Solution
{
public:
    // The intution to solve this question is that storing optimal frequency of
    // the points in a map, the bottom left point and top right is incremented
    // and bottom right and top left is decremented which as whole cancels the
    // inner points. Check If the absolute sum of all the points comes out to be 4

    bool isRectangleCover(vector<vector<int>> &r)
    {
        // map to store optimal frequency of the points
        map<pair<int, int>, int> m;
        // count of all the points
        int ct = 0;

        // process each rectangle
        for (auto P : r)
        {
            // increment bottom left and top right point
            m[{P[0], P[1]}]++;
            m[{P[2], P[3]}]++;
            // decrement bottom right and top left point
            m[{P[0], P[3]}]--;
            m[{P[2], P[1]}]--;
        }

        for (auto it : m)
        {
            ct += abs(it.second);
        }
        // only checking 4 non-zero points will not
        // cover edge case for overlapping rectanges
        if (ct == 4)
        {
            return true;
        }
        return false;
    }
};
