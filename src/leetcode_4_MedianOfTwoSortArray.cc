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
    double leetcode_4_MedianOfTwoSortArray(vector<int>& nums1, vector<int>& nums2) {

    }
};

TEST(leetcode_4_MedianOfTwoSortArray, leetcode_4_MedianOfTwoSortArray_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
//    EXPECT_EQ(s.leetcode_4_MedianOfTwoSortArray(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
