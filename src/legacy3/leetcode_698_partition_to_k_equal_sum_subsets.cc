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
    int m_target = 0;
    bool helper(vector<int>& nums, int k, int start, int curSum, vector<bool>& visited){
        if (k == 1) return true;
        if(curSum > m_target) return false;
        if(curSum == m_target) return helper(nums, k-1, 0, 0, visited);

        for (int i = start; i < nums.size(); ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            if(helper(nums, k, i+1, curSum+nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }

    bool leetcode_698_partition_to_k_equal_sum_subsets(vector<int>& nums, int k) {

        log(INFO_) << "before nums are ";
        copy(nums.begin(), nums.end(), log(" "));
        log() << endl;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0) return false;
        m_target = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());

        vector<bool> visited(nums.size(), false);
        return helper(nums, k, 0, 0, visited);
    }
};

TEST(leetcode_698_partition_to_k_equal_sum_subsets, leetcode_698_partition_to_k_equal_sum_subsets_1)
{
    Solution s;
    vector<int> in1 = {4, 3, 2, 3, 5, 2, 1};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int k = 4;
    bool ans = true;
    EXPECT_EQ(s.leetcode_698_partition_to_k_equal_sum_subsets(in1, k), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
