/**
 * 
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    vector<int> leetcode_94_binary_tree_inorder_traversal(TreeNode* root) {
        vector<int> ans;
        // 1 recursion
        // inorderTraversal(root, ans);


        // 2 Iteration1
        stack<TreeNode*> s;
        // s.push(root);
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root=root->left;
            }

            root = s.top(); s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
        // https://github.com/aqiugroup/LeetCode_Projects/blob/master/saveIssue/leetcode_solutions/94.md

        // 3 Iteration2
//        stack<TreeNode*> s;
//        TreeNode* r = root;
//        while (!s.empty() || r) {
//            if (r) {
//                s.push(r);
//                ans.push_back(r->val);
//                r = r->left;
//            } else {
//                r = s.top(); s.pop();
//                r = r->right;
//            }
//        }

        return ans;
    }
};

TEST(leetcode_94_binary_tree_inorder_traversal, leetcode_94_binary_tree_inorder_traversal_1)
{
    Solution s;
    Tree in1{1, NULL, 2, 3};
    vector<int> ans = {1, 3, 2};
    EXPECT_EQ(s.leetcode_94_binary_tree_inorder_traversal(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
