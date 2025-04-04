/**
 * 
硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

示例1:

 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
示例2:

 输入: n = 10
 输出：4
 解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1
说明：

注意:

你可以假设：

0 <= n (总金额) <= 1000000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_ans = 0;
    map<int, int> m;
    int helper(vector<int>& list, int index, int target, vector<vector<int> >& m) {
        if (m[target][index] > 0) return m[target][index];

        if (index >= list.size()-1) return 1;

        int cnt = 0, val = list[index];
        for (int i = 0; i * val <= target; i++) {
            cnt = (cnt + helper(list, index+1, target-i*val, m))%1000000007;
        }
        return m[target][index] = cnt;
    }

    int leetcode_08_11_m_coin_lcci(int n) {
        vector<int> list {25, 10, 5, 1};
        // 1 recursion
        // vector<vector<int> > m(n + 1, vector<int>(list.size()));
        // return helper(list, 0, n, m);

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int coin : list) {
            for (int i = coin; i <= n; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[n];
    }
};

TEST(leetcode_08_11_m_coin_lcci, leetcode_08_11_m_coin_lcci_2)
{
    Solution s;
    int in4 = 10;
    int ans2 = 4;
    EXPECT_EQ(s.leetcode_08_11_m_coin_lcci(in4), ans2);

}

TEST(leetcode_08_11_m_coin_lcci, leetcode_08_11_m_coin_lcci_1)
{
    Solution s;
    int in4 = 5;
    int ans2 = 2;
    EXPECT_EQ(s.leetcode_08_11_m_coin_lcci(in4), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
