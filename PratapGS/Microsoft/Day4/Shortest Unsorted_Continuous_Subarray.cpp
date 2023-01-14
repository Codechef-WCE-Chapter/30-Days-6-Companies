/* O(2n) be the time complexity Approch is simple like firsly traverse from start if found any case where nums[i] > nums[i+1] return its index;
Similarly Traverse from back and if nums[i] < nums[i+1] return that index;
subtract two indices;
*/
 

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minindex =0;
        int maxindex =0;
        int max= nums[0];
        int min = nums[n-1];


        for(int i =1; i <n;i++) {
            if(max > nums[i]){
                minindex = i+1;
               
            }
            else{
                max = nums[i];
            }
        }
        

        for(int i =n-2; i >= 0;i--) {
            if(min < nums[i]){
                maxindex = i ;
            }
            else{
                min = nums[i];
            }
        }

        return minindex - maxindex ;
    }
};
