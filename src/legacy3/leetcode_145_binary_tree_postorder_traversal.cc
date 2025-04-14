/**
 * 

给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 *
 */
#include "headers.h"

class Solution
{
public:
    void postorderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        postorderTraversal(root->left, ans);
        postorderTraversal(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> leetcode_145_binary_tree_postorder_traversal(TreeNode* root) {

        vector<int> ans;
        // 1 recursion
        // postorderTraversal(root, ans);

        // 2 Iteration1
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* r = s.top(); s.pop();
            if (!r) continue;

            ans.insert(ans.begin(), r->val);
            s.push(r->left);
            s.push(r->right);
        }
        return ans;

        // 3 Iteration2
//        stack<TreeNode*> s;
//        TreeNode* r = root;
//        while (!s.empty() || r) {
//            if (r) {
//                s.push(r);
//                ans.insert(ans.begin(), r->val);
//                r = r->right;
//            } else {
//                r = s.top(); s.pop();
//                r = r->left;
//            }
//        }
//        return ans;
    }
};

TEST(leetcode_145_binary_tree_postorder_traversal, leetcode_145_binary_tree_postorder_traversal_1)
{
    Solution s;
    Tree in1{1, NULL, 2, 3};
    vector<int> ans = {3, 2, 1};
    EXPECT_EQ(s.leetcode_145_binary_tree_postorder_traversal(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
