/**
 * 
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
//    int leetcode_107_binary_tree_level_order_traversal_ii(vector<int> &nums) {
    vector<vector<int>> leetcode_107_binary_tree_level_order_traversal_ii(TreeNode* root) {

        vector<vector<int>> rst;
        if(!root) return rst;

        vector<int> layerRst;
        deque<vector<int>> dequeRst;

        queue<TreeNode *> queueMember;
        queueMember.push(root);
        TreeNode* nodeTemp = nullptr;

        while(!queueMember.empty()){
            int layerSize = queueMember.size();

            for (int i = 0; i < layerSize; ++i) {
                nodeTemp = queueMember.front();
                layerRst.push_back(nodeTemp->val);

                if (nodeTemp->left != nullptr){
                    queueMember.push(nodeTemp->left);
                }

                if (nodeTemp->right != nullptr){
                    queueMember.push(nodeTemp->right);
                }

                queueMember.pop();
            }

            dequeRst.push_front(layerRst);
            layerRst.clear();
        }

        nodeTemp = nullptr;
//        cout << " dequerst size " << dequeRst.size() << endl;
        int size = dequeRst.size();
        for (int j = 0; j < size; ++j) {
            rst.push_back(dequeRst.front());
            dequeRst.pop_front();
        }

        return rst;
    }
};

TEST(leetcode_107_binary_tree_level_order_traversal_ii, leetcode_107_binary_tree_level_order_traversal_ii_1)
{
    Solution s;
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    vector<vector<int>> rst;
    rst.push_back(vector<int>{15, 7});
    rst.push_back(vector<int>{9, 20});
    rst.push_back(vector<int>{3});

    EXPECT_EQ(s.leetcode_107_binary_tree_level_order_traversal_ii(head), rst);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
