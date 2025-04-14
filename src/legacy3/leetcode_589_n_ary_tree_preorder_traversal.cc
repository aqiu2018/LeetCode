/**
 * 
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :
返回其前序遍历: [1,3,5,6,2,4]。

说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void helper(Node* root,vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        int size = root->children.size();
        for (int i = 0; i < size; i++) {
            helper(root->children[i], ans);
        }
    }
    vector<int> leetcode_589_n_ary_tree_preorder_traversal(TreeNode* root) {
        vector<int> ans;
        // 1. recursion
        // helper(root, ans);
        // return ans;


        // 2. Iteration
        stack<Node*> s{{root}};
        while (!s.empty()) {
            Node* t = s.top(); s.pop();
            if (!t) continue;

            ans.push_back(t->val);
            for (int i = (int)t->children.size() - 1; i >= 0; --i) {
                s.push(t->children[i]);
            }
        }
        return ans;
    }
};

TEST(leetcode_589_n_ary_tree_preorder_traversal, leetcode_589_n_ary_tree_preorder_traversal_1)
{
    Solution s;
    Tree in1{1, NULL, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.leetcode_589_n_ary_tree_preorder_traversal(in1.root), ans1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
