/*Rotate Function: https://leetcode.com/problems/rotate-function/ */

#include<bits/stdc++.h>
using namespace std;

// Observation -> Formulate -> Repeat

/*
Approach:
T.C=O(n)

ex: 4,2,3,6
Observation: 
Instead of computing function values each time after rotation by loop -> compute func (index) only once and use it to compute rest func values.
Formulate the next index value as: 
index.1 = 4*0 + 2*1 + 3*2 + 6*3
index.2 = 4*1 + 2*2 + 3*3 + 6*0 --> (observe pattern in 1 and 2)
can also be written as:
    index.2 = 4*0 + 2*1 + 3*2 + 6*3 + (4 + 2 + 3 + 6) - 6*4  (evaluating tail to 0)
            = index.1 + sum - n*nums[i] (n= tail)  (sum = 4+2+3+6)

*/

class Solution {
public:
    // int find_fun(vector<int> & curr_vec)
    // {
    //     int res =0;
    //     for(int i=0; i<curr_vec.size(); i++)
    //     {
    //         res+= (i*curr_vec[i]);  
    //     }
    //     return res;
    // }

    int maxRotateFunction(vector<int>& nums) {
        int k=nums.size() , max_res=INT_MIN, tail=0, index=0, sum=0 ;
        // sum= sum(nums);
        for(int i=0; i<k; i++)
        {
            index+= (i*nums[i]);  
            sum+=nums[i];
        }
        max_res= index;
        int it =k-1;
        while(it--)
        {
                tail = nums.back();
                nums.pop_back();
                index += sum - ( (k)*tail);
                max_res= max(index, max_res  );
        } 
            // while(k--)
            // {
            //     // if(find_fun(nums) < 0)
            //     // max_res = find_fun(nums);
            //     // else if(find_fun(nums) > 0)
            //     // {
            //     //     if(find_fun(nums) > max_res)
            //     //     max_res = find_fun(nums);
            //     // }
                
            //     max_res= max(max_res,find_fun(nums)  );

            //     tail = nums.back();
            //     nums.pop_back();
            //     nums.insert(nums.begin(), tail);


            // }
        
        return max_res;
    }
};