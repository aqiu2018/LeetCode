/**
 * 
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void preorderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }

    vector<int> leetcode_144_binary_tree_preorder_traversal(TreeNode* root) {

        vector<int> ans;
        // 1 recursion
        // preorderTraversal(root, ans);

        // 2 Iteration1
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* r = s.top(); s.pop();
            if (!r) continue;

            ans.push_back(r->val);
            s.push(r->right);
            s.push(r->left);
        }
        return ans;

        // 3 Iteration2
        stack<TreeNode*> s;
        TreeNode* r = root;
        while (!s.empty() || r) {
            if (r) {
                s.push(r);
                ans.push_back(r->val);
                r = r->left;
            } else {
                r = s.top(); s.pop();
                r = r->right;
            }
        }

        return ans;
    }
};

TEST(leetcode_144_binary_tree_preorder_traversal, leetcode_144_binary_tree_preorder_traversal_1)
{
    Solution s;
    Tree in1{1, NULL, 2, 3};
    vector<int> ans = {1, 2, 3};
    EXPECT_EQ(s.leetcode_144_binary_tree_preorder_traversal(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
