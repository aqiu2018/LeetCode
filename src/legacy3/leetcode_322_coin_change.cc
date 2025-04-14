/**
 * 
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_322_coin_change(vector<int>& coins, int amount) {

//        sort(coins.begin(), coins.end(), greater<int>());

        vector<int> dp(amount + 1, amount + 1);
        dp[0]=0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]]+1);
            }
        }
        return dp[amount]>amount ? -1 : dp[amount];
    }
};

TEST(leetcode_322_coin_change, leetcode_322_coin_change_8)
{
    Solution s;
    vector<int> in1 = {8, 2, 3, 6};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 3;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 7), ans);
}

TEST(leetcode_322_coin_change, leetcode_322_coin_change_7)
{
    Solution s;
    vector<int> in1 = {186, 419, 83, 408};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 20;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 6249), ans);
}

TEST(leetcode_322_coin_change, leetcode_322_coin_change_6)
{
    Solution s;
    vector<int> in1 = {2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = -1;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 3), ans);
}
TEST(leetcode_322_coin_change, leetcode_322_coin_change_5)
{
    Solution s;
    vector<int> in1 = {};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = -1;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 4), ans);
}
TEST(leetcode_322_coin_change, leetcode_322_coin_change_4)
{
    Solution s;
    vector<int> in1 = {5};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = -1;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 4), ans);
}
TEST(leetcode_322_coin_change, leetcode_322_coin_change_3)
{
    Solution s;
    vector<int> in1 = {1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 4), ans);
}
TEST(leetcode_322_coin_change, leetcode_322_coin_change_2)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 2;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 4), ans);
}
TEST(leetcode_322_coin_change, leetcode_322_coin_change_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_322_coin_change(in1, 3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
