/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
*/

#include<bits/stdc++.h>
using namespace std;

//Approach 1: use a vector
//T.C : O(nlogn)-> sorting
//S.C: O(n) ->vector

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=0, h=nums.size()-1, start_point=0, end_point=0;
        //Using an auxiliary array
        vector<int> vect =nums;
        sort(vect.begin(), vect.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=vect[i])
            {
            start_point =i;
            break;
            }

        }
        for(int i= nums.size()-1; i>=0; i--)
        {
            if(nums[i]!=vect[i])
            {
            end_point =i;
            break;
            }

        }
        if(nums==vect)
        return 0;
        else
        return abs(end_point - start_point) +1;

        
        //Two Pointer Approach:

        // if(nums.size()==1)
        // {
        //     return 0;
        // }
        // else{
        // while(l< h)
        // {

        //     if(nums[l] <= nums[l+1] && end_point==0 && start_point==0 )
        //     {
        //         l++;
        //     }
        //     else if( nums[h] > nums[h-1]) 
        //     {   
        //         h--;
        //     }
        //     else if(nums[l] >  nums[l+1] && end_point !=0)
        //     {
             
        //       start_point =l;
           
        //       if( nums[h]<=nums[h-1]  && nums[h]!=nums[l])
        //       {
        //         end_point =h;
        //         return abs(end_point - start_point) +1;
        //         break;
        //       }
        //       else if(nums[h]<=nums[h-1]  && nums[h]==nums[l] )
        //       {
        //           h--;
        //           if(nums[h] > nums[h-1])
        //           {
        //           end_point= h;
        //           return abs(end_point - start_point)  ;
        //           break;
        //           }
        //       }
        //       h--;
        //     }
        //     else if(nums[h] < nums[h-1])
        //     {  
        //       end_point=h;
        //       cout<<end_point<<endl;
        //       if( nums[l]>nums[l+1] )
        //       {
        //         start_point=l;
        //         // cout<<start_point<<endl;
        //         return abs(end_point - start_point) + 1;
        //         break;
        //       }
        //       l++;
        //     }

        // }
        // // if(abs(end_point - start_point) !=0)
        // // return abs(end_point - start_point) +1 ;
        
        // }
        
        // return abs(end_point - start_point)  ;
    }
};