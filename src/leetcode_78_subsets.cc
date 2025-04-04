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
    int leetcode_78_subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        for (auto n : nums) {
            int size = ans.size();
            for(int i = 0; i< size; i++)  {
                vector<int> a = ans[i];
                a.push_back(n);
                ans.push_back(a);
            }
        }

        return ans;
    }
};

TEST(leetcode_78_subsets, leetcode_78_subsets_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_78_subsets(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
