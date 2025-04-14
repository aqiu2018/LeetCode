/**
 * 
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (!root) return;

        if(ans.size() == level) ans.push_back(vector<int>{});
        ans[level].push_back(root->val);
        if (root->left) levelOrder(root->left, level + 1, ans);
        if (root->right) levelOrder(root->right, level + 1, ans);
    }
    vector<vector<int>> leetcode_102_binary_tree_level_order_traversal(TreeNode* root) {

        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        return ans;

        if (!root) return ans;

        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front(); q.pop();
                if (t) {
                    q.push(t->left);
                    q.push(t->right);
                    tmp.push_back(t->val);
                }
            }
            if (tmp.size() > 0) ans.push_back(tmp);
        }
        return ans;
    }
};

TEST(leetcode_102_binary_tree_level_order_traversal, leetcode_102_binary_tree_level_order_traversal_1)
{
    Solution s;
    Tree in1{3,9,20,NULL,NULL,15,7};
    vector<vector<int>> ans = {
            {3},
            {9,20},
            {15,7}
    };
    EXPECT_EQ(s.leetcode_102_binary_tree_level_order_traversal(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
