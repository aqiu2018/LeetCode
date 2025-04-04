/**
 * 
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10]
输出: 1
 

注意:

你可以假设：

0 <= amount (总金额) <= 5000
1 <= coin (硬币面额) <= 5000
硬币种类不超过 500 种
结果符合 32 位符号整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    // https://www.cnblogs.com/grandyang/p/4840713.html

    map<pair<int, int>, int> m;
    int helper(int amount, vector<int>& coins, int id) {

        cout << " amount " << amount << " id " << id << " coin size " << coins.size() << endl;
        if(amount == 0) return 1;
        else if(id==coins.size()) return 0;
        else if(id==coins.size()-1) return amount%coins[id] == 0;

        if(m.count({amount, id})) return m[{amount, id}];

        int val = coins[id], ans = 0;
        for (int i = 0; i * val <= amount; ++i) {
            ans += helper(amount - i * val, coins, id+1);
        }

        return m[{amount, id}] = ans;
    }
    int leetcode_518_coin_change_2(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.empty()) return 0;

//        return helper(amount, coins, 0);

        // dp[i][j] 表示用前i个硬币组成钱数为j的不同组合方法
//        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
//        dp[0][0] = 1;
//        for (int i = 1; i <= coins.size(); ++i) {
//            dp[i][0] = 1;
//            for (int j = 1; j <= amount; ++j) {
//                dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
//            }
//        }
//        return dp[coins.size()][amount];

        //由上面的二维dp转为一维
        int change(int amount, vector<int>& coins) {
            vector<int> dp(amount + 1, 0);
            dp[0] = 1; //不取就为0 ？
            for (int coin : coins) {
                for (int i = coin; i <= amount; ++i) {
                    dp[i] += dp[i - coin];
                }
            }
            return dp[amount];
        }
    }
};

TEST(leetcode_518_coin_change_2, leetcode_518_coin_change_2_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 5};
    int amount = 5;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_518_coin_change_2(amount, in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
