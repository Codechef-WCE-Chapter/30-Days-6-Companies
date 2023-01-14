/*

Approach:
If we apply Brute force so It will take O(N^2) time to get the solution;
but in brute force we are reapeting a step of finding GCD of numsDivide Vector

1) Create a function which find the value of GCD of Vector NumsDivide
2) if GCD % nums[i] == 0 then return that index and break;
3) If we traverse whole array still GCD % nums[i] == 0 then maintain a 
pointer traversecnt which tells us that entire array is traversed but 
condition is not satistfied so return -1

}
return cnt or i (index)


*/
class Solution {
public:

// Function to find gcd of array of
// numbers
int findGCD(vector<int> &numsDivide, int m)
{
  int result = numsDivide[0];
  for (int i = 1; i < m; i++)
  {
    result = gcd(numsDivide[i], result);
  
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}


    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size();
        int i=0;
        int m = numsDivide.size();
        int cnt = 0;
    sort(nums.begin(),nums.end());
        int k = findGCD(numsDivide,m);


       int traversecnt =0;

        for(int i =0; i <n ; i++){
            if(k % nums[i] ==0){
                cnt =i;
                break;
            }
            traversecnt++;
        }

        if(traversecnt == n){
            return -1;
        }
        else{
            return cnt;
        }
    // if(cnt == 0){
    //     return -1;
    // }

    // else{

    //     return cnt;
    // }

    return i;
    }
};
