/**
 *
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 **/

#include "headers.h"

class Solution
{
public:
    vector<vector<int>> rst;
    void preorder(TreeNode* root, vector<int>& result, int sumUp, int sum){
        if(!root)  return;

        result.push_back(root->val);
        sumUp += root->val;
        if (root->left== nullptr && root->right == nullptr && sumUp == sum) rst.push_back(result);

        preorder(root->left, result, sumUp, sum);
        if(root->left != nullptr) result.pop_back();

        preorder(root->right, result, sumUp, sum);
        if(root->right != nullptr) result.pop_back();
    }

    vector<vector<int>> leetcode_113_path_sum_ii(TreeNode* root, int sum) {

        vector<int> result;
        int sumUp = 0;
        preorder(root, result, sumUp, sum);

        return rst;
    }

};

TEST(leetcode_113_path_sum_ii, leetcode_113_path_sum_ii_1)
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> ans = {{5,4,11,2},{5,8,4,5}};
    EXPECT_EQ(s.leetcode_113_path_sum_ii(root, 22), ans);
}

TEST(leetcode_113_path_sum_ii, leetcode_113_path_sum_ii_2)
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(8);


    vector<vector<int>> ans = {{5,8}};
    EXPECT_EQ(s.leetcode_113_path_sum_ii(root, 13), ans);
}

TEST(leetcode_113_path_sum_ii, leetcode_113_path_sum_ii_3)
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(8);


    vector<vector<int>> ans = {{5,4, 2}};
    EXPECT_EQ(s.leetcode_113_path_sum_ii(root, 11), ans);
}

TEST(leetcode_113_path_sum_ii, leetcode_113_path_sum_ii_4)
{
    Solution s;
    TreeNode* root = new TreeNode(5);


    vector<vector<int>> ans = {{5}};
    EXPECT_EQ(s.leetcode_113_path_sum_ii(root, 5), ans);
}

TEST(leetcode_113_path_sum_ii, leetcode_113_path_sum_ii_5)
{
    Solution s;
    TreeNode* root = new TreeNode(5);


    vector<vector<int>> ans = {};
    EXPECT_EQ(s.leetcode_113_path_sum_ii(root, 6), ans);
}

TEST(leetcode_113_path_sum_ii, leetcode_113_path_sum_ii_6)
{
    Solution s;
    TreeNode* root = nullptr;


    vector<vector<int>> ans = {};
    EXPECT_EQ(s.leetcode_113_path_sum_ii(root, 6), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}