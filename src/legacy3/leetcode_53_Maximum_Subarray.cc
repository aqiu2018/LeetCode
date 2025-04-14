/**
 * 
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_53_Maximum_Subarray(vector<int>& nums)
    {
        int count = 0, sum = 0, maxSum = INT_MIN;

        while (count < nums.size()){
            sum += nums[count++];
            if (sum > maxSum) maxSum = sum;
            if(sum < 0)  sum = 0;
        }

        // TODO dp

        return maxSum;

    }
};

TEST(leetcode_53_Maximum_Subarray, leetcode_53_Maximum_Subarray_1)
{
    Solution s;
    vector<int> in = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = 6;
    EXPECT_EQ(s.leetcode_53_Maximum_Subarray(in), 6);
}

TEST(leetcode_53_Maximum_Subarray, leetcode_53_Maximum_Subarray_2)
{
    Solution s;
    vector<int> in = {-2};
    int ans = -2;
    EXPECT_EQ(s.leetcode_53_Maximum_Subarray(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
