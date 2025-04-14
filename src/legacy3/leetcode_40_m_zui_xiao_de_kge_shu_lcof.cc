/**
 * 
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。



示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]


限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_40_m_zui_xiao_de_kge_shu_lcof(vector<int>& arr, int k) {
        vector<int> ans;

        priority_queue<int> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.push(arr[i]);
            if(pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

TEST(leetcode_40_m_zui_xiao_de_kge_shu_lcof, leetcode_40_m_zui_xiao_de_kge_shu_lcof_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    int k = 2;
    vector<int> ans = {2, 1};
    EXPECT_EQ(s.leetcode_40_m_zui_xiao_de_kge_shu_lcof(in1, k), ans);
}

TEST(leetcode_40_m_zui_xiao_de_kge_shu_lcof, leetcode_40_m_zui_xiao_de_kge_shu_lcof_2)
{
    Solution s;
    vector<int> in1 = {0, 1, 2, 1};
    int k = 1;
    vector<int> ans = {0};
    EXPECT_EQ(s.leetcode_40_m_zui_xiao_de_kge_shu_lcof(in1, k), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
