* Problem : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

* Solution : 

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = size(nums), x = 0;
        vector<int> temp(nums);

        sort(temp.begin(), temp.end());
        if(temp == nums) { return 0; }
        if(n == 1) { return 0; }

        int left = 0, right = 0;

        for(int i = 0; i < n; i++){
            if(temp[i] != nums[i]){
                left = i;
                break;
            }
        }

        for(int i = n - 1; i >= 0; --i){
            if(temp[i] != nums[i]){
                right = i;
                break;
            }
        }

        return right - left + 1;
    }
};