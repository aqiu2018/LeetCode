/**
 * 
给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

示例:

输入:
         1
       /   \
      2     3
输出: 1
解释:
结点的坡度 2 : 0
结点的坡度 3 : 0
结点的坡度 1 : |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1
注意:

任何子树的结点的和不会超过32位整数的范围。
坡度的值不会超过32位整数的范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-tilt
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int tiltOrder(TreeNode* root, int& ans) {
        if (!root) return 0;

        int left = 0, right = 0;
        if(root->left) left = tiltOrder(root->left, ans);
        if(root->right) right = tiltOrder(root->right, ans);
        ans += abs(left-right);
        return left+right+root->val;
    }
    int leetcode_563_binary_tree_tilt(TreeNode* root) {
        int ans = 0;
        tiltOrder(root, ans);
        return ans;
    }
};

TEST(leetcode_563_binary_tree_tilt, leetcode_563_binary_tree_tilt_1)
{
    Solution s;
    Tree in1{1,2,3};
    int ans = 1;
    EXPECT_EQ(s.leetcode_563_binary_tree_tilt(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
