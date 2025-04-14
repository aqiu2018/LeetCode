/**
 * 
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"


// TODO qzc recursion is better idea
class Solution
{
public:
    bool leetcode_100_same_tree(TreeNode* p, TreeNode* q) {

        std::stack<pair<TreeNode*, TreeNode*>> nodeStack;
        TreeNode* pTemp = p, *qTemp = q;
        while(!nodeStack.empty() || pTemp || qTemp){
            if(pTemp && qTemp){
                if(pTemp->val == qTemp->val){
                    nodeStack.push({pTemp, qTemp});
                    pTemp = pTemp->left;
                    qTemp = qTemp->left;
                    continue;
                }

                return false;
            }else if(pTemp == nullptr && qTemp == nullptr){
                pair<TreeNode*, TreeNode*> temp = nodeStack.top();
                pTemp = temp.first;
                qTemp = temp.second;
                nodeStack.pop();

                pTemp = pTemp->right;
                qTemp = qTemp->right;
            }else{
                return false;
            }
        }

        if(pTemp == nullptr && qTemp == nullptr){
            return true;
        }
    }
};

TEST(leetcode_100_same_tree, leetcode_100_same_tree_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
//    EXPECT_EQ(s.leetcode_100_same_tree(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
