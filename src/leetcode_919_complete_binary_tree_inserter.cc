/**
 * 
完全二叉树是每一层（除最后一层外）都是完全填充（即，结点数达到最大）的，并且所有的结点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：

CBTInserter(TreeNode root) 使用头结点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v) 将 TreeNode 插入到存在值为 node.val = v  的树中以使其保持完全二叉树的状态，并返回插入的 TreeNode 的父结点的值；
CBTInserter.get_root() 将返回树的头结点。
 

示例 1：

输入：inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
输出：[null,1,[1,2]]
示例 2：

输入：inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
输出：[null,3,4,[1,2,3,4,5,6,7,8]]
 

提示：

最初给定的树是完全二叉树，且包含 1 到 1000 个结点。
每个测试用例最多调用 CBTInserter.insert  操作 10000 次。
给定结点或插入结点的每个值都在 0 到 5000 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complete-binary-tree-inserter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        head = root;
        q.push(root);
        while(!q.empty()) { // 保存最后两行，两个子节点没满的所有节点
            TreeNode* tmp = q.front();
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            if (tmp->left && tmp->right) q.pop();
            else break;
        }
    }

    int insert(int v) {
        TreeNode* tmp = q.front();

        TreeNode* newNode = new TreeNode(v);
        if (!tmp->left) tmp->left = newNode;
        else tmp->right = newNode;
        q.push(newNode);

        if (tmp->left && tmp->right) q.pop();

        return tmp->val;
    }

    TreeNode* get_root() {
        return head;
    }

    TreeNode* head;
    queue<TreeNode*> q;
};
class Solution
{
public:
    int leetcode_919_complete_binary_tree_inserter(TreeNode* root) {

        CBTInserter* obj = new CBTInserter(root);
        int param_1 = obj->insert(7);
        TreeNode* param_2 = obj->get_root();

        return 1;
    }
};

TEST(leetcode_919_complete_binary_tree_inserter, leetcode_919_complete_binary_tree_inserter_1)
{
    Solution s;
    Tree in1{2,1,3};
    int ans = 1;
    EXPECT_EQ(s.leetcode_919_complete_binary_tree_inserter(in1.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
