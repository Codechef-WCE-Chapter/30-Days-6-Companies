class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
      int k=numsDivide[0];
      for(int i=1;i<numsDivide.size();i++)
      {
          k=__gcd(k,numsDivide[i]);
      }
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size();i++)
        if(!(k%nums[i])) return i;

      return -1;
      
    }
};
