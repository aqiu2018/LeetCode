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
    int leetcode_62_m_yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof(int n, int m) {
        int pos = 0; // 最终活下来那个人的初始位置
        for(int i = 2; i <= n; i++){
            pos = (pos + m) % i;  // 每次循环右移
        }
        return pos;

        // vector<int> v;
        // for(int i = 0; i < n; i++){
        //     v.push_back(i);
        // }

        // int i = 0;
        // while(v.size()!=1){
        //     i=(i-1+m)%v.size();
        //     v.erase(v.begin()+i);
        // }

        // return v[0];

    }
};

TEST(leetcode_62_m_yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof, leetcode_62_m_yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof_1)
{
    Solution s;
    int in1 = 6;
    int in2 = 3;
    int ans = 1;
    EXPECT_EQ(s.leetcode_62_m_yuan_quan_zhong_zui_hou_sheng_xia_de_shu_zi_lcof(in1, in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
