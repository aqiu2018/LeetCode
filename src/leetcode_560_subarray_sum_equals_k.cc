/**
 *
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 **/

#include "headers.h"

class Solution
{
public:
    int leetcode_560_subarray_sum_equals_k(vector<int>& nums, int k) {

        map<int, int> mapSumNums{{0, 1}};
        int sum = 0, rst = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            cout << "a "<< mapSumNums.count(sum - k) << " rst " << rst << endl;
            if(mapSumNums.count(sum - k))  { rst = rst + mapSumNums[sum-k];}
            cout << "b "<< mapSumNums.count(sum - k) << " rst " << rst << endl;

            if(mapSumNums.count(sum))  mapSumNums[sum]++;
            else mapSumNums[sum] = 1;
        }

        return rst;
    }
};

TEST(leetcode_560_subarray_sum_equals_k, leetcode_560_subarray_sum_equals_k_1)
{
    Solution s;
    vector<int> in = {1, 1, 1};
    int ans = 2;
//    EXPECT_EQ(s.leetcode_560_subarray_sum_equals_k(in, 2), ans);
}

TEST(leetcode_560_subarray_sum_equals_k, leetcode_560_subarray_sum_equals_k_2)
{
    Solution s;
    vector<int> in = {1, 1, 1, 2, 0, 2, -1, 1, 0, 2};
    int ans = 13;
    EXPECT_EQ(s.leetcode_560_subarray_sum_equals_k(in, 2), ans);
}

TEST(leetcode_560_subarray_sum_equals_k, leetcode_560_subarray_sum_equals_k_3)
{
    Solution s;
    vector<int> in = {1, 1, 1, 2};
    int ans = 3;
//    EXPECT_EQ(s.leetcode_560_subarray_sum_equals_k(in, 2), ans);
}

TEST(leetcode_560_subarray_sum_equals_k, leetcode_560_subarray_sum_equals_k_4)
{
    Solution s;
    vector<int> in = {0,0,0,0,0,0,0,0,0,0};
    int ans = 55;
    EXPECT_EQ(s.leetcode_560_subarray_sum_equals_k(in, 0), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}