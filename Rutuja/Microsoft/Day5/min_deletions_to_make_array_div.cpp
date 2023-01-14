/*
https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
Approach: cal gcd of vect2 and -> check if gcd or a no. div by gcd exists in vect1
T.C : O(nlogn) -> sorting
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int flag_exists=0, count=0, num=numsDivide[0];

        for(int i=1; i<numsDivide.size(); i++)
        {
            num = __gcd(num, numsDivide[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            if(num == nums[i] || num % nums[i]==0)
            flag_exists=1;
        }
        if(flag_exists==0)
        count= -1;
        else if(flag_exists==1)
        {
            count=0;
            for(int i=0; i<nums.size(); i++)
            {
                if(num  % nums[i] && nums[i] < num)
                {
                    count++;
                }
                else
                break;  
            }
        }

    return count;
    }
};

//Approach 2: 

        // if(flag_exists==0)
        // count=-1;
        // else
        // {
        //     for(int i=0; i<nums.size(); i++)
        //     {
        //         if(nums[i] < num && (num % nums[i])!=0 )
        //         count++;
        //     }
        // }
        // for(int i=0; i<nums.size(); i++)
        // {
        //     int n=nums[i];
        //     for(int j=0; j<numsDivide.size(); )
        //     {
        //         if(numsDivide[j] % n !=0)
        //         {
        //             flag= -1;
        //             break;
        //         }
        //         else if(numsDivide[j] % n == 0)
        //         {
        //             j++;
        //             flag=1;
        //         }
        //     }
       
        //     if(flag==1)
        //     {
        //         if(n < target)
        //         target =n;
        //         else if(n == target)
        //         {
        //             target =n;
        //             break;
        //         }

        //     }

        // }
    
        // if(target==INT_MAX)
        //     return -1;
        // else
        // {
        //     for(int i=0; i<nums.size(); i++)
        //     {
        //         if(nums[i] < target )
        //         count++;
        //     }
        // }
