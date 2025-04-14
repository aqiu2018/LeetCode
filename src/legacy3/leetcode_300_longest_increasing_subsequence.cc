/**
 * 
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_300_longest_increasing_subsequence(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) dp[i] = max(dp[j]+1, dp[i]);
            }
        }

        int maxValue = dp[0];
        for (int k = 0; k < nums.size(); ++k) {
            maxValue = max(maxValue, dp[k]);
        }

        return maxValue;
    }
};

TEST(leetcode_300_longest_increasing_subsequence, leetcode_300_longest_increasing_subsequence_1)
{
    Solution s;
    vector<int> in = {10,9,2,5,3,7,101,18};
    int ans = 4;
    EXPECT_EQ(s.leetcode_300_longest_increasing_subsequence(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
