/**
 * 
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_128_longest_consecutive_sequence(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(s.count(nums[i]) == 0) continue;
            s.erase(nums[i]);
            int pre = nums[i] - 1, next = nums[i] + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            ans = max(ans, next - pre - 1);
        }
        return ans;
    }
};

TEST(leetcode_128_longest_consecutive_sequence, leetcode_128_longest_consecutive_sequence_1)
{
    Solution s;
    vector<int> in1 = {1, 100, 4, 88,2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_128_longest_consecutive_sequence(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
