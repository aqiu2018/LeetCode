/**
 * 
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:
输入: [1, 2, 3, 5]
输出: false

解释: 数组不能分割成两个元素和相等的子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool leetcode_416_partition_equal_subset_sum(vector<int>& nums) {

        int sum = 0;
        for(auto n : nums) sum+=n;
        if(sum & 0x1) return false;
        sum = sum/2;

        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(auto n : nums){
            for (int i = sum; i >= n ; --i) {
                dp[i] = dp[i] || dp[i-n];
            }
        }
        return dp[sum];




//        vector<vector<int>> knapsack(nums.size(), vector<int>{-1});
//        knapsack[0][0] = 0;
//        if (nums[0] <= sum) knapsack[0][nums[0]] = nums[0];
//
//        for (int i = 1; i < nums.size(); ++i) {
//            for (int j = 0; j < sum+1; ++j) {
//                if(knapsack[i-1][j] > 0) knapsack[i][j] = knapsack[i-1][j];
//            }
//
//            for (int k = 0; k < sum - nums[i]; ++k) {
//                if(knapsack[i-1][k] >= 0)
//                    knapsack[i][k] = max(knapsack[i-1][k]+nums[i], knapsack[i][k+nums[i]]);
//            }
//
//
//        }
//
//
//        return 1;
    }
};

TEST(leetcode_416_partition_equal_subset_sum, leetcode_416_partition_equal_subset_sum_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_416_partition_equal_subset_sum(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
