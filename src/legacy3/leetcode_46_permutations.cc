/**
 * 
 * Copyright (c) 2018
 * 
 * @file
 * @author   qzc (1457615966@qq.com)
 * @date     2019-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-11-20
 * Modified By:    qzc (1457615966@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<int>> m_ans;
    void helper(vector<int>& nums, vector<int>& ans, unordered_set<int>& path) {

        if (nums.size() == 0) return;
        if (ans.size() == nums.size()) {
            m_ans.push_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (path.count(nums[i])) continue;
            path.insert(nums[i]);

            ans.push_back(nums[i]);
            helper(nums, ans, path);
            ans.erase(ans.end()-1);

            path.erase(nums[i]);
        }
    }
    vector<vector<int>> leetcode_46_permutations(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> path;
        helper(nums, ans, path);
        return m_ans;
    }
};

TEST(leetcode_46_permutations, leetcode_46_permutations_1)
{
    Solution s;
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> ans2 = {
            {1,2,3},
            {1,3,2},
            {2,1,3},
            {2,3,1},
            {3,1,2},
            {3,2,1},
    };
    EXPECT_EQ(s.leetcode_46_permutations(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
