class Solution {
public:
    // o(NlogN)
    // int findUnsortedSubarray(vector<int>& nums) {
    //     vector<int>copy = nums;
    //     int cnt = 0;
    //     sort(copy.begin(),copy.end());
    //     int starti=nums.size(),endi=0;
    //     for(int i = 0;i<nums.size();i++){
    //         if(nums[i]!=copy[i]){
    //             cnt++;
    //            if(i<starti)starti = i;
    //            if(i>endi)endi = i;
    //         }
    //     }
    //     if(cnt == 0)return 0;
    //     return (endi-starti +1);
    // }

    // o(N)
    int findUnsortedSubarray(vector<int>& nums) {
       int max_ele = INT_MIN;
       int min_ele = INT_MAX;
       int cnt = 0;
       for(int i = 0;i<nums.size();i++){
           if(i!=nums.size()-1 && nums[i]>nums[i+1]){
               cnt++;
           max_ele = max(nums[i],max_ele);
           }
       }
       for(int i = 0;i<nums.size();i++){
           if(i!=0 && nums[i]<nums[i-1]){
           min_ele = min(nums[i],min_ele);
       }
       }
      
       if(cnt==0)return 0;
       int ind1,ind2;
       for(int i = 0;i<nums.size();i++){
           if(nums[i]>min_ele){
               ind1 = i;
               break;
           }
       }
       cout<<ind1<<" ";
       for(int i = nums.size()-1;i>=0;i--){
           if(nums[i]<max_ele){
               ind2 = i;
               break;
           }
       }
       cout<<ind2<<" ";
       return(ind2-ind1+1);
    }
};