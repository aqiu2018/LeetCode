/**
 * 
给定一个二叉搜索树的根结点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \
    1   3

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 

注意：

二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。
本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void helper(TreeNode* root, int& pre, int& ans) {
        if (!root) return;

        helper(root->left, pre, ans);
        if (pre != -1) ans = min(ans, root->val - pre);
        pre = root->val;
        helper(root->right, pre, ans);
    }
    int leetcode_783_minimum_distance_between_bst_nodes(TreeNode* root) {

        int pre = -1;
        int ans = INT_MAX;
        helper(root, pre, ans);
        return ans;
    }
};

TEST(leetcode_783_minimum_distance_between_bst_nodes, leetcode_783_minimum_distance_between_bst_nodes_1)
{
    Solution s;
    Tree in1{4,2,6,1,3,NULL,NULL};
    int ans = 1;
    int ansRet = s.leetcode_783_minimum_distance_between_bst_nodes(in1.root);
    EXPECT_EQ(ansRet, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
