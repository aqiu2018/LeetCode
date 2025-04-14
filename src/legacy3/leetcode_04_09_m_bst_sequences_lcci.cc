/**
 * 
从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。给定一个由不同节点组成的二叉树，输出所有可能生成此树的数组。

示例:
给定如下二叉树

        2
       / \
      1   3
返回:

[
   [2,1,3],
   [2,3,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bst-sequences-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void helper(TreeNode* root, queue<TreeNode*> path, vector<int> result, vector<vector<int>>& ans) {
        if (root->left) path.push(root->left);
        if (root->right) path.push(root->right);

        if (path.size() == 0) ans.push_back(result);

        int size = path.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* tmp = path.front();path.pop();
            result.push_back(tmp->val);
            helper(tmp, path, result, ans);
            result.pop_back();
            path.push(tmp);
        }

    }
    vector<vector<int>> leetcode_04_09_m_bst_sequences_lcci(TreeNode* root) {

        vector<vector<int>> ans;
        if (!root) return {{}};

        queue<TreeNode*> path;
        vector<int> result{root->val};
        helper(root, path, result, ans);
        return ans;
    }
};

TEST(leetcode_04_09_m_bst_sequences_lcci, leetcode_04_09_m_bst_sequences_lcci_3)
{
    Solution s;
    Tree in1{NULL};
    vector<vector<int>> ans = {
            {},
    };
    vector<vector<int>> ansRet = s.leetcode_04_09_m_bst_sequences_lcci(in1.root);
    EXPECT_EQ(ansRet, ans);
}

TEST(leetcode_04_09_m_bst_sequences_lcci, leetcode_04_09_m_bst_sequences_lcci_2)
{
    Solution s;
    Tree in1{1};
    vector<vector<int>> ans = {
            {1},
    };
    vector<vector<int>> ansRet = s.leetcode_04_09_m_bst_sequences_lcci(in1.root);
    EXPECT_EQ(ansRet, ans);
}

TEST(leetcode_04_09_m_bst_sequences_lcci, leetcode_04_09_m_bst_sequences_lcci_1)
{
    Solution s;
    Tree in1{2,1,3};
    vector<vector<int>> ans = {
            {2, 1, 3},
            {2, 3, 1}
    };
    vector<vector<int>> ansRet = s.leetcode_04_09_m_bst_sequences_lcci(in1.root);
    EXPECT_EQ(ansRet, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
