/**
 * 
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
例如，
给定二叉搜索树:
        4
       / \
      2   7
     / \
    1   3
和值: 2
你应该返回如下子树:
      2
     / \
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    TreeNode* helper(TreeNode* root, int val) {
        if (!root) NULL;

        if (root->val == val) return root;
        else if (root->val > val) return helper(root->left, val);
        else return helper(root->right, val);
    }
    TreeNode* leetcode_700_search_in_a_binary_search_tree(TreeNode* root, int val) {
        return helper(root, val);
    }
};

TEST(leetcode_700_search_in_a_binary_search_tree, leetcode_700_search_in_a_binary_search_tree_1)
{
    Solution s;
    Tree in1{4,2,7,1,3};
    int in2 = 2;
    Tree ans{2,1,3};
    TreeNode* ansRet = s.leetcode_700_search_in_a_binary_search_tree(in1.root, in2);
    EXPECT_EQ(is_same_tree(ansRet, ans.root), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
