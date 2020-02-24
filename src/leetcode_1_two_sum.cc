/**
 * 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_1_two_sum(vector<int>& nums, int target) {

        unordered_map<int, int> record;

        for(int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];
            if( record.find(complement) != record.end() ){
                int res[2] = {record[complement], i};

                return vector<int>(res, res+2);
            }
            record[nums[i]] = i;
        }

        throw invalid_argument("the input has no solution");
    }
};

TEST(leetcode_1_two_sum, leetcode_1_two_sum_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    vector<int> ans = {0, 1};
    // std::cout << s.leetcode_1_two_sum(in, 3)[0] << std::endl;
    EXPECT_TRUE(s.leetcode_1_two_sum(in, 3) == ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
