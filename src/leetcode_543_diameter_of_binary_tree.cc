/**
 * 
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \
      4   5
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_maxPath = 0;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left + right > m_maxPath)  m_maxPath = left + right;

        return max(left, right)+1;
    }

    int leetcode_543_diameter_of_binary_tree(TreeNode* root) {
        if(root == nullptr) return 0;

        return max(m_maxPath, dfs(root->left) + dfs(root->right));
    }
};

TEST(leetcode_543_diameter_of_binary_tree, leetcode_543_diameter_of_binary_tree_2)
{
    Solution s;
    Tree in{1, 2, 2, 2,2, NULL, NULL,2, NULL, 2, NULL, 2, 2,2};
    in.print();
    int ans = 6;
    EXPECT_EQ(s.leetcode_543_diameter_of_binary_tree(in.root), ans);
}

TEST(leetcode_543_diameter_of_binary_tree, leetcode_543_diameter_of_binary_tree_1)
{
    Solution s;
    Tree in{1, 2, 3, 4, NULL, NULL, NULL};
    in.print();
    int ans = 3;
    EXPECT_EQ(s.leetcode_543_diameter_of_binary_tree(in.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
