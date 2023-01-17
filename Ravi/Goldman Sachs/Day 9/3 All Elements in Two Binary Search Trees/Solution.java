class Solution {
    void inOrder(TreeNode root, List<Integer> ans) {
        if(root == null) return;
        
        inOrder(root.left, ans);
        ans.add(root.val);
        inOrder(root.right, ans);
        
    }
    
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> ans = new ArrayList<>();
        inOrder(root1, ans);
        inOrder(root2, ans);
        
        Collections.sort(ans);
        return ans;
    }
}
