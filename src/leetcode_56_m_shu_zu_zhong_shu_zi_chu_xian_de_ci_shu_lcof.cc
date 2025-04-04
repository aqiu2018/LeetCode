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
    vector<int> leetcode_56_m_shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_lcof(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            if (m.count(n) == 0) m[n] = 1;
            else m.erase(n);
        }

        vector<int> ans;
        unordered_map<int, int>::iterator itBegin = m.begin();
        while (itBegin != m.end()) {
            ans.push_back(itBegin->first);
            itBegin++;
        }

        return ans;
    }
};

TEST(leetcode_56_m_shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_lcof, leetcode_56_m_shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_lcof_1)
{
    Solution s;
    vector<int> ans1 = {1, 3, 2};
    vector<int> in3 = {4,1,4,6};
    EXPECT_EQ(s.leetcode_56_m_shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_lcof(in3), ans1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
