/**
 * 
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：
输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int helper(TreeNode* root) {
        if(!root) return 0;

        int right = helper(root->right);
        root->val += right;
        if(root->left) root->left->val += root->val;
        int left = helper(root->left);
        return root->val;

    }
    TreeNode* leetcode_538_convert_bst_to_greater_tree(TreeNode* root) {

        int ret = helper(root);
        cout << "ret " << ret << endl;
        return root;
    }
};

TEST(leetcode_538_convert_bst_to_greater_tree, leetcode_538_convert_bst_to_greater_tree_2)
{
    Solution s;
    Tree in1{};

    in1.root = nullptr;
    Tree ans{18, 20, 13};
    bool b = is_same_tree(s.leetcode_538_convert_bst_to_greater_tree(in1.root), nullptr);
    EXPECT_EQ(b, true);
}

TEST(leetcode_538_convert_bst_to_greater_tree, leetcode_538_convert_bst_to_greater_tree_1)
{
    Solution s;
    Tree in1{5,2,13};

    Tree ans{18, 20, 13};
    bool b = is_same_tree(s.leetcode_538_convert_bst_to_greater_tree(in1.root), ans.root);
    EXPECT_EQ(b, true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
