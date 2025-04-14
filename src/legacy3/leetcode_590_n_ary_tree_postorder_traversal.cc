/**
 * 
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :
返回其后序遍历: [5,6,3,2,4,1].


说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void helper(Node* root,vector<int>& ans) {
        if (!root) return;

        for (Node* child : root->child) {
            helper(child, ans);
        }

        ans.push_back(root->val);
    }
    vector<int> leetcode_590_n_ary_tree_postorder_traversal(TreeNode* root) {
        vector<int> ans;
        // 1. recursion
        // helper(root, ans);
        // return ans;

        // 2. Iteration
        stack<Node*> s{{root}};
        while (!s.empty()) {
            Node* t = s.top(); s.pop();
            if (!t) continue;

            ans.insert(ans.begin(), t->val);
            for (int i = (int)t->children.size() - 1; i >= 0; --i) {
                s.push(t->children[i]);
            }
        }
        return ans;
    }
};

TEST(leetcode_590_n_ary_tree_postorder_traversal, leetcode_590_n_ary_tree_postorder_traversal_1)
{
    Solution s;
    Tree in1{1, NULL, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.leetcode_590_n_ary_tree_postorder_traversal(in1.root), ans1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
