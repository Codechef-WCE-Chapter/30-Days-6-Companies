class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    unordered_map<int,int>mpp;
    int x= -1;
    int y= -1;
    for(int i=0;i<nums.size();i++) mpp[i]=nums[i];
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
    if(mpp[i]!=nums[i]){
         if(x== -1) x=i;
         y=i;
    }
    }
  //  cout<<x<<" "<<y<<endl;
    if(y== -1 && x== -1) return 0;
    return y-x+1;
    }
};
