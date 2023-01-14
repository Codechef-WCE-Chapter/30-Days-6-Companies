/*
https://leetcode.com/problems/airplane-seat-assignment-probability/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {

       if(n==1)
       return 1;
     
       return double(1)/2;

    }
};