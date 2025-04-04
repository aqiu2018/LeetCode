/**
 * 
给出一个完全二叉树，求出该树的节点个数。

说明：
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:
输入:
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int helper(TreeNode* root) {
        if (!root) return 0;

        TreeNode* tmp = root;
        int leftHeight = 0, rightHeight = 0;
        while(tmp) {
            tmp = tmp->left;
            leftHeight++;
        }
        tmp = root;
        while(tmp) {
            tmp = tmp->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight) return pow(2, leftHeight) -1;

        return 1 + helper(root->left) + helper(root->right);
    }
    int leetcode_222_count_complete_tree_nodes(TreeNode* root) {

        return helper(root);
    }
};

TEST(leetcode_222_count_complete_tree_nodes, leetcode_222_count_complete_tree_nodes_1)
{
    Solution s;
    Tree in1{2,1,3};
    int ans = 3;
    int ansRet = s.leetcode_222_count_complete_tree_nodes(in1.root);
    EXPECT_EQ(ansRet, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
