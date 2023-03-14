class Solution {
    public int rob(TreeNode root) {
        if(root == null) return 0;
        
        int l = rob(root.left);
        int r = rob(root.right);
        
        int ll = 0;
        if(root.left != null && root.left.left != null) ll += root.left.left.val;
        if(root.left != null && root.left.right != null) ll += root.left.right.val;
        int rr = 0;
        if(root.right != null && root.right.left != null) rr += root.right.left.val;
        if(root.right != null && root.right.right != null) rr += root.right.right.val;
        
        int ans = l + r;
        ans = Math.max(ans, ll + rr + root.val);
        ans = Math.max(ans, l + rr);
        ans = Math.max(ans, r + ll);
        
        return root.val = ans;
    }
}
