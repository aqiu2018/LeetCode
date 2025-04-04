/**
 * 
 * Copyright (c) 2018
 * 
 * @file
 * @author   qzc (1457615966@qq.com)
 * @date     2019-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-11-20
 * Modified By:    qzc (1457615966@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    void helper(TreeNode* t1, TreeNode* t2, TreeNode*& ans) {
        if(!t1) {
            ans = t2;
            return;
        }
        if(!t2){
            ans = t1;
            return;
        }

        ans = new TreeNode(t1->val+t2->val);
        helper(t1->left, t2->left, ans->left);
        helper(t1->right, t2->right, ans->right);
    }

    TreeNode* leetcode_617_merge_two_binary_trees(TreeNode* t1, TreeNode* t2) {
        TreeNode *ans;
        helper(t1, t2, ans);
        return ans;
    }
};

TEST(leetcode_617_merge_two_binary_trees, leetcode_617_merge_two_binary_trees_1)
{
    Solution s;
    Tree t1 {1,3,2,5};
    Tree t2 {2,1,3,NULL,4,NULL,7};
    Tree ans {3, 4, 5, 5, 4, NULL, 7};
    TreeNode* a = s.leetcode_617_merge_two_binary_trees(t1.root, t2.root);
    EXPECT_EQ( is_same_tree(a, ans.root), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
