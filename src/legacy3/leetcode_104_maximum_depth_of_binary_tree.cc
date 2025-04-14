/**
 * 
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_104_maximum_depth_of_binary_tree(TreeNode* root) {

        if(!root) return 0;

        int left = leetcode_104_maximum_depth_of_binary_tree(root->left);
        int right = leetcode_104_maximum_depth_of_binary_tree(root->right);

        return max(left, right)+1;
    }
};

TEST(leetcode_104_maximum_depth_of_binary_tree, leetcode_104_maximum_depth_of_binary_tree_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_104_maximum_depth_of_binary_tree(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
