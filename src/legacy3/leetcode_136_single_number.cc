/**
 * 
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_136_single_number(vector<int>& nums) {
        unordered_map<int, int> mMap;
        for (int i = 0; i < nums.size(); ++i) {
            if(mMap.count(nums[i]) == 0) mMap.insert(make_pair(nums[i], 1));
            else mMap.erase(nums[i]);
        }

        return mMap.begin()->first;
    }
};

TEST(leetcode_136_single_number, leetcode_136_single_number_3)
{
    Solution s;
    vector<int> in1 = {4};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_136_single_number(in1), ans);
}

TEST(leetcode_136_single_number, leetcode_136_single_number_2)
{
    Solution s;
    vector<int> in1 = {4, 1, 1, 2, 2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_136_single_number(in1), ans);
}

TEST(leetcode_136_single_number, leetcode_136_single_number_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_136_single_number(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
