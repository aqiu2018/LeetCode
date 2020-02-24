/**
 * 
给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。

注意:
 nums 数组的总和是一定在 32 位有符号整数范围之内的。

示例 1:

输入: nums = [1, -1, 5, -2, 3], k = 3
输出: 4
解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。
示例 2:

输入: nums = [-2, -1, 2, 1], k = 1
输出: 2
解释: 子数组 [-1, 2] 和等于 1，且长度最长。

 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_325_maximum_size_subarray_sum_equals_k(vector<int>& nums, int k) {

        unordered_map<int, int> sumMap;
        int maxLen = 0;
        int sum =0;

        sumMap[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(sumMap.find(sum) == sumMap.end()){
                sumMap.insert(pair<int,int>(sum, i+1));
            }

            if (sumMap.find(sum - k) != sumMap.end()){
                maxLen = max(maxLen, i+1-sumMap[sum - k]);
            }
        }

        return maxLen;
    }
};

TEST(leetcode_325_maximum_size_subarray_sum_equals_k, leetcode_325_maximum_size_subarray_sum_equals_k_1)
{
    Solution s;
    vector<int> in = {-2, -1, 1, 2, -4, 1, 4, 5, -5, 6};
    int ans = 8;
    EXPECT_EQ(s.leetcode_325_maximum_size_subarray_sum_equals_k(in, 3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
