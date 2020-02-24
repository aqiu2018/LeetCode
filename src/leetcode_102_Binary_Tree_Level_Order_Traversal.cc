/**
 * 
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"



class Solution
{
public:
//    struct TreeNode {
//        int val;
//        TreeNode *left;
//        TreeNode *right;
//        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//    };

    vector<vector<int>> leetcode_102_Binary_Tree_Level_Order_Traversal(TreeNode* root)
    {
        vector<vector<int>> rst;
        vector<int> layerRst;
        if(root == nullptr) return rst;

        queue<TreeNode *> stackMember;
        stackMember.push(root);

        while(!stackMember.empty()){
            int layerSize = stackMember.size();
            for (int i = 0; i < layerSize; ++i) {

                layerRst.push_back(stackMember.front()->val);

                if (stackMember.front()->left != nullptr){
                    stackMember.push(stackMember.front()->left);
                }
                if (stackMember.front()->right != nullptr){
                    stackMember.push(stackMember.front()->right);
                }
                stackMember.pop();
            }
            rst.push_back(layerRst);
            layerRst.clear();
        }

        return rst;
    }
};

TEST(leetcode_102_Binary_Tree_Level_Order_Traversal, leetcode_102_Binary_Tree_Level_Order_Traversal_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.leetcode_102_Binary_Tree_Level_Order_Traversal(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
