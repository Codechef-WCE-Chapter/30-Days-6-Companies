#include <algorithm>
#include <iostream>
#include <vector>
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

using namespace std;
int main()
{
    vector<vector<int>> preR{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    int numOfC = 5;
    cout << canFinish(numOfC, preR) << endl;
}