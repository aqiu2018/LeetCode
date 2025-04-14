/**
 * 
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，
 并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:
输入: nums = [1,2,3,1], k = 3, t = 0
输出: true

示例 2:
输入: nums = [1,0,1,1], k = 1, t = 2
输出: true

示例 3:
输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool leetcode_220_contains_duplicate_iii(vector<int>& nums, int k, int t) {

        // |i - j| <= k && |nums[i] - nums[j]|<= t
        // 1. bruce
//        int j;
//        for (int i = 0; i < nums.size(); ++i) {
//            j = i-1;
//            while(j>=0 && j >= i - k){
//                if(abs(long(nums[i]) - long(nums[j--])) <= t) return true;
//            }
//        }

        //2. slide window
        set<int> memo;
        for (int i = 0; i < nums.size(); ++i) {
            set<int>::iterator it = memo.lower_bound(double(nums[i]) - t);
            if(it != memo.end() && *it <= (double)nums[i]+t) return true;

            memo.insert(nums[i]);
            if(memo.size() == k+1) memo.erase(nums[i-k]);
        }

        return false;
    }


};

TEST(leetcode_220_contains_duplicate_iii, leetcode_220_contains_duplicate_iii_1)
{
    Solution s;
    vector<int> in = {1,2,3,1};
    bool ans = true;
    EXPECT_EQ(s.leetcode_220_contains_duplicate_iii(in, 3, 0), ans);
}

TEST(leetcode_220_contains_duplicate_iii, leetcode_220_contains_duplicate_iii_2)
{
    Solution s;
    vector<int> in = {1,0,1,1};
    bool ans = true;
    EXPECT_EQ(s.leetcode_220_contains_duplicate_iii(in, 1, 2), ans);
}

TEST(leetcode_220_contains_duplicate_iii, leetcode_220_contains_duplicate_iii_3)
{
    Solution s;
    vector<int> in = {1,5,9,1,5,9};
    bool ans = false;
    EXPECT_EQ(s.leetcode_220_contains_duplicate_iii(in, 2, 3), ans);
}

TEST(leetcode_220_contains_duplicate_iii, leetcode_220_contains_duplicate_iii_4)
{
    Solution s;
    vector<int> in = {-1,2147483647};
    bool ans = false;
    EXPECT_EQ(s.leetcode_220_contains_duplicate_iii(in, 1, 2147483647), ans);
}

TEST(leetcode_220_contains_duplicate_iii, leetcode_220_contains_duplicate_iii_5)
{
    Solution s;
    vector<int> in = {1,-2147483647};
    bool ans = false;
    EXPECT_EQ(s.leetcode_220_contains_duplicate_iii(in, 1, 2147483647), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
