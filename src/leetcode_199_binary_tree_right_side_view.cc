/**
 * 
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_199_binary_tree_right_side_view(TreeNode* root) {
        if (!root) return vector<int>();

        vector<int> ans;
        queue<TreeNode*> q{{root}};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = q.front();
                if (tmp && i==size-1) ans.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                q.pop();
            }
        }

        return ans;
    }
};

TEST(leetcode_199_binary_tree_right_side_view, leetcode_199_binary_tree_right_side_view_3)
{
    Solution s;
    Tree in1{4,3,6,1,NULL,5,NULL,NULL,2};
    vector<int> ans1 = {4,6,5,2};
    EXPECT_EQ(s.leetcode_199_binary_tree_right_side_view(in1.root), ans1);
}

TEST(leetcode_199_binary_tree_right_side_view, leetcode_199_binary_tree_right_side_view_2)
{
    Solution s;
    Tree in1{1,2,3,4};
    vector<int> ans1 = {1, 3, 4};
    EXPECT_EQ(s.leetcode_199_binary_tree_right_side_view(in1.root), ans1);
}

TEST(leetcode_199_binary_tree_right_side_view, leetcode_199_binary_tree_right_side_view_1)
{
    Solution s;
    Tree in1{1,2,3,NULL,5,NULL,4};
    vector<int> ans1 = {1, 3, 4};
    EXPECT_EQ(s.leetcode_199_binary_tree_right_side_view(in1.root), ans1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
