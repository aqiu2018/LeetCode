/**
 * 
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    deque<TreeNode*> q1;
    deque<TreeNode*> q2;

    bool helper(TreeNode* t1, TreeNode* t2) {
        if(t1==t2) return true;
        if(t1== nullptr || t2== nullptr) return false;

        return (t1->val == t2->val) &&
        helper(t1->left, t2->right) &&
        helper(t1->right, t2->left);

    }

    bool leetcode_101_symmetric_tree(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);

        if(!root) return true;
        deque<TreeNode*> q1, q2;
        q1.push_back(root->left);
        q2.push_back(root->right);

        while(!q1.empty()){
            int size1 = q1.size();
            int size2 = q2.size();
            if(size1 != size2) return false;
            for (int i = 0; i < size1; ++i) {
                TreeNode* t1 = q1.front(), *t2 = q2.front();
                q1.pop_front();q2.pop_front();
                if(t1==t2) continue;
                if(t1== nullptr || t2== nullptr) return false;
                if(t1->val !=t2->val) return false;

                q1.push_back(t1->left);
                q1.push_back(t1->right);

                q2.push_back(t2->right);
                q2.push_back(t2->left);
            }
        }

        return true;
    }
};
TEST(leetcode_101_symmetric_tree, leetcode_101_symmetric_tree_2)
{
    Solution s;
//    Tree in1 = {1,2,2,3,4,4,3};
    Tree in1 = {1,2,2,NULL,3,NULL,3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = false;
    EXPECT_EQ(s.leetcode_101_symmetric_tree(in1.root), ans);
}

TEST(leetcode_101_symmetric_tree, leetcode_101_symmetric_tree_1)
{
    Solution s;
    Tree in1 = {1,2,2,3,4,4,3};
//    Tree in1 = {1,2,2,null,3,null,3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_101_symmetric_tree(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
