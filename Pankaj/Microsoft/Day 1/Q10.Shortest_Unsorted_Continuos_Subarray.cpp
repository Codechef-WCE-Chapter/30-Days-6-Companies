//Microsoft: Q10.Shortest Unsorted Continuos Subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(nums);
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<n&&nums[i]==arr[i]){
            i++;
        }
        if(i==n){
            return 0;
        }
        while(j>=i&&nums[j]==arr[j]){
            j--;
        }
        return j-i+1;
    }
};