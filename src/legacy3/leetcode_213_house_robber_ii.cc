/**
 * 
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_213_house_robber_ii(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n-1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        int maxValue = dp[n-1];

        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return max(dp[n], maxValue);
    }
};

TEST(leetcode_213_house_robber_ii, leetcode_213_house_robber_ii_6)
{
    Solution s;
    vector<int> in1 = {0};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 0;
    EXPECT_EQ(s.leetcode_213_house_robber_ii(in1), ans);
}

TEST(leetcode_213_house_robber_ii, leetcode_213_house_robber_ii_5)
{
    Solution s;
    vector<int> in1 = {0,1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_213_house_robber_ii(in1), ans);
}

TEST(leetcode_213_house_robber_ii, leetcode_213_house_robber_ii_4)
{
    Solution s;
    vector<int> in1 = {0};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 0;
    EXPECT_EQ(s.leetcode_213_house_robber_ii(in1), ans);
}

TEST(leetcode_213_house_robber_ii, leetcode_213_house_robber_ii_1)
{
    Solution s;
    vector<int> in1 = {2, 3,2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 3;
    EXPECT_EQ(s.leetcode_213_house_robber_ii(in1), ans);
}

TEST(leetcode_213_house_robber_ii, leetcode_213_house_robber_ii_2)
{
    Solution s;
    vector<int> in1 = {1,2, 3, 1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_213_house_robber_ii(in1), ans);
}

TEST(leetcode_213_house_robber_ii, leetcode_213_house_robber_ii_3)
{
    Solution s;
    vector<int> in1 = {3, 2, 3, 4, 2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 7;
    EXPECT_EQ(s.leetcode_213_house_robber_ii(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
