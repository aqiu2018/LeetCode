/**
 * 
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void zigzagLevelOrder(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (!root) return;

        if (ans.size() == level) ans.push_back(vector<int>{});
        if (level&0x1) ans[level].insert(ans[level].begin(), root->val);
        else ans[level].push_back(root->val);

        if (root->left) zigzagLevelOrder(root->left, level + 1, ans);
        if (root->right) zigzagLevelOrder(root->right, level + 1, ans);
    }
    vector<vector<int>> leetcode_103_binary_tree_zigzag_level_order_traversal(TreeNode* root) {

        vector<vector<int>> ans;
        zigzagLevelOrder(root, 0, ans);
        return ans;
    }
};

TEST(leetcode_103_binary_tree_zigzag_level_order_traversal, leetcode_103_binary_tree_zigzag_level_order_traversal_1)
{
    Solution s;
    Tree in1{3,9,20,NULL,NULL,15,7};
    vector<vector<int>> ans = {
            {3},
            {20, 9},
            {15,7}
    };
    EXPECT_EQ(s.leetcode_103_binary_tree_zigzag_level_order_traversal(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
