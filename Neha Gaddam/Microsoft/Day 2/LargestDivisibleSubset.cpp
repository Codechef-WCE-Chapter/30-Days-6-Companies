class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        //sorted the array
        sort(nums.begin(),nums.end());
        //Count to count how many numbers the element can divide or can be divisinl
        vector<int>count(n),index(n); //index array for retriving the element
        int lastIndex=0,mx=0;
        for(int i=0;i<n;i++)
        {
            index[i]=i; 
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and count[i]<1+count[j]) //count of jth element +1 is greater then ith element
                {
                    count[i]=1+count[j]; //add the element to the list
                    index[i]=j; //Assign the j index
                }
            }

            if(count[i]>mx) //IF the curr element subset is greater then global one
            {
                mx=count[i]; //Add the element as maximum
                lastIndex=i; //Store lastIndex to retrive the array back
            }

        }

        vector<int>ans;
        ans.push_back(nums[lastIndex]);  //First add the last element
        
        while(index[lastIndex]!=lastIndex) 
        {
            lastIndex=index[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        return ans;
    }
};