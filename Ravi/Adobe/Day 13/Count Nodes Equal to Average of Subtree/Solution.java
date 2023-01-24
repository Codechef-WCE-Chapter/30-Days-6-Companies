class Pair {
    int f;
    int s;
    
    Pair(int a, int b) {
        f = a;
        s = b;
    }
    
}
class Solution {
    
    int ans = 0;
    
    Pair average(TreeNode root) {
        
        if(root == null) return new Pair(0, 0);
        
        Pair p = average(root.left);
        Pair q = average(root.right);
        
        int n = p.s + q.s + 1;
        int sum = p.f + q.f + root.val;
        
        if(sum / n == root.val) ans++;
        
        return new Pair(sum, n);
        
    }
    
    public int averageOfSubtree(TreeNode root) {
        
        average(root);
        
        return ans;
        
    }
}
