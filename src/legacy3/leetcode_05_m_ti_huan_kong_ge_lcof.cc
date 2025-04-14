/**
 * 
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    string leetcode_05_m_ti_huan_kong_ge_lcof(string s) {


        string ans = "";
        for(auto c : s) {
            if (c==' ') ans += "%20";
            else ans+=c;
        }

        return ans;
    }
};
TEST(leetcode_05_m_ti_huan_kong_ge_lcof, leetcode_05_m_ti_huan_kong_ge_lcof_2)
{
    Solution s;
    string in1 = " We are happy.";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "%20We%20are%20happy.";
    EXPECT_EQ(s.leetcode_05_m_ti_huan_kong_ge_lcof(in1), ans);
}

TEST(leetcode_05_m_ti_huan_kong_ge_lcof, leetcode_05_m_ti_huan_kong_ge_lcof_1)
{
    Solution s;
    string in1 = "We are happy.";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "We%20are%20happy.";
    EXPECT_EQ(s.leetcode_05_m_ti_huan_kong_ge_lcof(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
