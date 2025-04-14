/**
 * 
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :
返回其层序遍历:
[
     [1],
     [3,2,4],
     [5,6]
]
说明:
树的深度不会超过 1000。
树的节点总数不会超过 5000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void levelOrder(Node* root, int level, vector<vector<int>>& ans) {
        if (!root) return;

        if(ans.size() == level) ans.push_back(vector<int>{});
        ans[level].push_back(root->val);
        for (auto child : root->children) levelOrder(child, level+1, ans);
    }
    vector<vector<int>> leetcode_429_n_ary_tree_level_order_traversal(Node* root) {

        vector<vector<int>> ans;
//        levelOrder(root, 0, ans);
//        return ans;

        if (!root) return ans;

        queue<Node*> q{{root}};
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                Node* t = q.front(); q.pop();
                if (t) {
                    tmp.push_back(t->val);
                    for (auto child : t->children) q.push(child);
                }
            }
            if (tmp.size() > 0) ans.push_back(tmp);
        }
        return ans;
    }
};

TEST(leetcode_429_n_ary_tree_level_order_traversal, leetcode_429_n_ary_tree_level_order_traversal_1)
{
    Solution s;
    Tree in1{1, NULL, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> in3 = {{1,2,3},{2,3,4}};
    int ans2 = 1;
    EXPECT_EQ(s.leetcode_429_n_ary_tree_level_order_traversal(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
