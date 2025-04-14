/**
 * 
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:

    void Iter(vector<int>& nums, int S, int start, int& ans){
        if(start >= nums.size()){
            if(S==0) ans++;
            return;
        }

        Iter(nums, S-nums[start], start+1, ans);
        Iter(nums, S+nums[start], start+1, ans);
    }
    int leetcode_494_target_sum(vector<int>& nums, int S) {

        // 1 Iteration
        int ans = 0;
        Iter(nums, S, 0, ans);
        return ans;

        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);// < sum, cnt>
        dp[0][0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (auto p : dp[i]) {
                dp[i+1][p.first + nums[i]] += p.second;
                dp[i+1][p.first - nums[i]] += p.second;
            }
        }

        return dp[n][S];
    }
};

TEST(leetcode_494_target_sum, leetcode_494_target_sum_1)
{
    Solution s;
    vector<int> in1 = {1, 1, 1, 1, 1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int S = 3;
    int ans = 5;
    EXPECT_EQ(s.leetcode_494_target_sum(in1, S), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
