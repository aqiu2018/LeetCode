/**
 * 
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool m_isBalance = true;
    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        if (abs(left-right) >1) m_isBalance = false;

        return max(left, right)+1;
    }
    bool leetcode_110_balanced_binary_tree(TreeNode* root) {
        helper(root);
        return m_isBalance;
    }
};

TEST(leetcode_110_balanced_binary_tree, leetcode_110_balanced_binary_tree_1)
{
    Solution s;
    Tree in1{3,9,20,NULL,NULL,15,7};
    bool ans = true;
    EXPECT_EQ(s.leetcode_110_balanced_binary_tree(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
