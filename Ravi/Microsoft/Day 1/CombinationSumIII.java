class Solution {
    
    List<List<Integer>> ans = new ArrayList<>();
    
    void combinationSum(int c, int i, List<Integer> curr, int n) {
        if(i == 0) {
            if(n == 0) ans.add(new ArrayList<>(curr));
            return;
        }
        
        for(int j = c + 1; j <= 9; j++) {
            curr.add(j);
            combinationSum(j, i - 1, curr, n - j);
            curr.remove(curr.size() - 1);
        }
        
    }
    
    public List<List<Integer>> combinationSum3(int k, int n) {
        
        List<Integer> curr = new ArrayList<>();
        combinationSum(0, k, curr, n);
        
        return ans;
    }
}
