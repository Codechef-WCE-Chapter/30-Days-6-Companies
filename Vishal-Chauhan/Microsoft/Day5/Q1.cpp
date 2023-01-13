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
    double nthPersonGetsNthSeat(double n)
    {
        if (n < 2)
            return 1.0;
        else
            return 0.5;
    }
};
int main()
{
    double n = 100;
    Solution s;
    cout << s.nthPersonGetsNthSeat(n) << endl;
    cout << s.nthPersonGetsNthSeat(1) << endl;
}