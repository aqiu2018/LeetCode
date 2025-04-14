/**
 * 
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> memo;
    int RecursiveRober(vector<int>& nums, int n) {
        if(n<0) return 0;
        if(memo[n] != -1) return memo[n];

        int maxValue = max(RecursiveRober(nums, n-1), RecursiveRober(nums, n-2)+nums[n]);
        memo[n] = maxValue;
        return maxValue;

    }
    int leetcode_198_house_robber(vector<int>& nums) {
        if(nums.size() == 0) return 0;

//        memo = vector<int>(nums.size(), -1);
//        return RecursiveRober(nums, nums.size()-1);

        vector<int> dp(nums.size()+1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];

    }
};

TEST(leetcode_198_house_robber, leetcode_198_house_robber_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3, 1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_198_house_robber(in1), ans);
}

TEST(leetcode_198_house_robber, leetcode_198_house_robber_2)
{
    Solution s;
    vector<int> in1 = {2, 7, 9, 3, 1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 12;
    EXPECT_EQ(s.leetcode_198_house_robber(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
