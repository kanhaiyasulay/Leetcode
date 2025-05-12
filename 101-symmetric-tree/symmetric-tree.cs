/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    bool Dfs(TreeNode root1, TreeNode root2)
    {
        if (root1 is null && root2 is null) 
            return true;

        if (root1?.val != root2?.val)
            return false;

        return Dfs(root1?.left, root2?.right) && 
               Dfs(root1?.right, root2?.left);
    }

    public bool IsSymmetric(TreeNode root) {
        return Dfs(root.left, root.right);
    }
}