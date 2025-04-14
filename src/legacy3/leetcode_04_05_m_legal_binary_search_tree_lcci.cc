/**
 * 
实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例 1:
输入:
    2
   / \
  1   3
输出: true
示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/legal-binary-search-tree-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    long m_max = INT_MAX;
    long m_min = INT_MIN;
    bool helper(TreeNode* root) {
        if (!root) true;
        if (root->val < INT_MIN || root->val > INT_MAX) return false;

        bool left = true, right = true;
        if(root->left) left = (root->left->val <= root->val) ? helper(root->left) : false;
        if(root->right) right = (root->right->val >= root->val) ? helper(root->right) : false;
        return left && right;
    }
    bool leetcode_04_05_m_legal_binary_search_tree_lcci(TreeNode* root) {
        return helper(root);

        if (root == NULL) return 1;
        function<int(TreeNode*, long long, long long)> dfs = [&](TreeNode* rt, long long lo, long long hi) {
            if (rt == NULL) return 1;
            if (!(rt->val > lo && rt->val < hi)) return 0;
            return dfs(rt->left, lo, rt->val) & dfs(rt->right, rt->val, hi);
        };
        return dfs(root, -1E18, 1E18);
    }
};

TEST(leetcode_04_05_m_legal_binary_search_tree_lcci, leetcode_04_05_m_legal_binary_search_tree_lcci_1)
{
    Solution s;
    Tree in1{2,1,3};
    bool ans = true;
    bool ansRet = s.leetcode_04_05_m_legal_binary_search_tree_lcci(in1.root);
    EXPECT_EQ(ansRet, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
