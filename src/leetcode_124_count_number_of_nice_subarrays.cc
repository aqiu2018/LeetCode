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
    int leetcode_124_count_number_of_nice_subarrays(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return 0;
        queue<int> q;

        int ans = 0;
        int l = 0, r = 0, count = 0;
        for (int i = 0; i < size; ++i) {
            if (q.size() < k) {
                if (nums[i]&0x1) {
                    q.push(nums[i]);
                    count = 0;
                }
            }
            while(q.size()==k) {
                if(nums[l]==q.front()) q.pop();
                l++;
                count++;
            }
            ans += count;
        }

        return ans;
    }
};

TEST(leetcode_124_count_number_of_nice_subarrays, leetcode_124_count_number_of_nice_subarrays_1)
{
    Solution s;
    vector<int> in1 = {1,1,2,1,1};
    int k = 3;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 2;
    EXPECT_EQ(s.leetcode_124_count_number_of_nice_subarrays(in1, k), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
