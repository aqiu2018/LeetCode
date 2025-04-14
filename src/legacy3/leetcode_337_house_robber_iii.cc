/**
 * 
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int dfs(TreeNode* root, int left, int right){
        if(!root) return 0;

        int ll=0, lr=0, rl=0, rr=0;
        left = dfs(root->left, ll, lr);
        right = dfs(root->right, rl, rr);

        return max(left+right, root->val+ll+lr+rl+rr);
    }
    int leetcode_337_house_robber_iii(TreeNode* root) {

        return dfs(root, 0, 0);
    }
};

TEST(leetcode_337_house_robber_iii, leetcode_337_house_robber_iii_1)
{
    Solution s;
    Tree head{3,2,3, NULL,3, NULL,1};
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 7;
    EXPECT_EQ(s.leetcode_337_house_robber_iii(head.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
