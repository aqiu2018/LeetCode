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

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1 p q 分别在左右子树中，则返回root
        // 2 p和q都在左子树，返回p q中位置最高的 或者 最深的root
        // 3 同2
        if (!root || p == root || q == root) return root;

        TreeNode *left = helper(root->left, p, q);
        if (left && left != p && left != q) return left; // p q都在左子树中，直接返回

        TreeNode *right = helper(root->right, p , q);
        if (left && right) return root;
        return left ? left : right;



//        if (!root) return NULL;
//        if (root->val == p->val || root->val == q->val) return root;
//
//        TreeNode* left = helper(root->left, p, q);
//        TreeNode* right = helper(root->right, p, q);
//
//        if (left && right) return root;
//        if (left) return left;
//        if (right) return right;
    }



#define N 2
#define M N+1

    TreeNode* leetcode_236_lowest_common_ancestor_of_a_binary_tree(TreeNode* root, TreeNode* p, TreeNode* q) {
        printf("%d", (M+1)*M/2);
        cout << " question1: " << (M+1)*M/2 << " pass score " << 135 * 0.7 << " can fail " << 135 * 0.3 << endl;

        const string a;
        const int b = 2;
        constexpr int c = 3;
        const int d = c;
        int e = c;
        cout << " qustion2: a " << a << " b " << b << " c " << c << " d " << d << " e " << e << endl;

        unsigned short f = 6; int g = -20;
        int h;
        (f+g) > 0 ? (h=1) : (h=0);
        cout << " question 3:  h " << h << endl;


        return helper(root, p, q);
    }
};


TEST(leetcode_236_lowest_common_ancestor_of_a_binary_tree, leetcode_236_lowest_common_ancestor_of_a_binary_tree_2)
{
    Solution s;
    Tree t{3,5,1,6,2,0,8,NULL,NULL,7,4};
    TreeNode *p = new TreeNode(5);
    TreeNode *q = new TreeNode(1);
    Tree ans = t;

    TreeNode* tmp = s.leetcode_236_lowest_common_ancestor_of_a_binary_tree(t.root, p, q);
    EXPECT_EQ( is_same_tree(tmp, ans.root), true);
}

TEST(leetcode_236_lowest_common_ancestor_of_a_binary_tree, leetcode_236_lowest_common_ancestor_of_a_binary_tree_1)
{
    Solution s;
    Tree t{5,6,2,NULL,NULL,7,4};
    TreeNode *p = new TreeNode(5);
    TreeNode *q = new TreeNode(4);
    Tree ans = t;

    TreeNode* tmp = s.leetcode_236_lowest_common_ancestor_of_a_binary_tree(t.root, p, q);
    EXPECT_EQ( is_same_tree(tmp, ans.root), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
