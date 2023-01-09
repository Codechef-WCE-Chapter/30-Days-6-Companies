class Solution {

    // For each element in range 1 to 9, we have
    // two choices:  
    //      i) We take it
    //      ii) We don't take it

    // - Use simple Recursion and Backtracking
    // - Take number num and make a recursive call
    //   for num-1
    // - Don't take number num and make a recusive 
    //   call for num - 1

    // - Base case is when num == 0. Check if given
    //   condition is satisified for this combination
    // - Condition here is whether sum == k
    // - If condition is satisified add the combination
    //   to our answer lists


    public List<List<Integer>> combinationSum3(int k, int n) {
        // stores all the lists of our ans
        List<List<Integer>> ans = new ArrayList<>();
        
        // while making recursive calls, will store
        // the currently taken elements
        List<Integer> curr = new ArrayList<>();
        
        helper(ans, curr, k, n, 9);
        
        return ans;
    }
    
    
    void helper(List<List<Integer>> ans, List<Integer> curr, int k, int n, int num) {

        // base case
        if (num == 0) {
            // if we have taken elements such that 
            // such that they add upto required sum,
            // value of n will be zero as we have
            // subtacted num from n for each num taken

            // and we restriction on number of elements
            // . for that we check if k == 0 as we have
            // have passed k-1 if we have taken any
            // element.

            if (n == 0 && k == 0) {
                // add the combination to our ans List
                ans.add(new ArrayList(curr));
            }
            return ;
        }
        
        // don't take the number num. required sum n
        // remains same
        helper(ans, curr, k, n, num-1);

        // take the number num. required sum now is
        // n - num
        curr.add(i);
        helper(ans, curr, k-1, n-num, num-1);

        // remove the added element once the recursive
        // call is over
        curr.remove(curr.size()-1);     
    }
}
