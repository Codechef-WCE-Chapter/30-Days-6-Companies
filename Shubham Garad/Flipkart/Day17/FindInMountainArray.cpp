/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int start=0;
        int peak=0;
        int end=arr.length()-1;

        // First we find the peak 
        while (start<end) 
        {
            int mid=start+(end-start)/2;
            if (arr.get(mid)<arr.get(mid+1)) 
            {
                start=peak=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        start=0, end=peak;

        // Find in the increasing array
        while (start<=end) 
        {
            int mid=start+(end-start)/2;

            if (arr.get(mid)<target) 
            {
                start=mid+1;
            }
            else if (arr.get(mid)>target)
            {
                end=mid-1;
            }
            else
            {
                return mid;
            } 
        }

        start=peak, end=arr.length()-1;
        // Find in decreasing array
        while (start<=end) 
        {
            int mid=start+(end-start)/2;

            if (arr.get(mid)>target)
            {
                start=mid+1;
            } 
            else if (arr.get(mid)<target)
            {
                end=mid-1;
            } 
            else 
            {
                return mid;
            }
        }
        return -1;
    }
};