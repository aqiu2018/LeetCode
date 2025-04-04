/**
 * 
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

 

示例 1：

输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：

输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
示例 3：

输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-masseuse-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_17_16_the_masseuse_lcci(vector<int>& nums) {

        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for (int i = 3; i < nums.size(); ++i) {
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }

        return max(dp[n-1], dp[n-2]);
    }
};

TEST(leetcode_17_16_the_masseuse_lcci, leetcode_17_16_the_masseuse_lcci_5)
{
    Solution s;
    vector<int> in1 = {1,2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 2;
    EXPECT_EQ(s.leetcode_17_16_the_masseuse_lcci(in1), ans);
}

TEST(leetcode_17_16_the_masseuse_lcci, leetcode_17_16_the_masseuse_lcci_4)
{
    Solution s;
    vector<int> in1 = {11};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 11;
    EXPECT_EQ(s.leetcode_17_16_the_masseuse_lcci(in1), ans);
}

TEST(leetcode_17_16_the_masseuse_lcci, leetcode_17_16_the_masseuse_lcci_3)
{
    Solution s;
    vector<int> in1 = {1,2,3,1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_17_16_the_masseuse_lcci(in1), ans);
}
TEST(leetcode_17_16_the_masseuse_lcci, leetcode_17_16_the_masseuse_lcci_2)
{
    Solution s;
    vector<int> in1 = {2,7,9,3,1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 12;
    EXPECT_EQ(s.leetcode_17_16_the_masseuse_lcci(in1), ans);
}

TEST(leetcode_17_16_the_masseuse_lcci, leetcode_17_16_the_masseuse_lcci_1)
{
    Solution s;
    vector<int> in1 = {2,1,4,5,3,1,1,3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 12;
    EXPECT_EQ(s.leetcode_17_16_the_masseuse_lcci(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
