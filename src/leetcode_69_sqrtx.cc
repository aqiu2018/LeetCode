/**
 * 
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_69_sqrtx(int x) {
        if (x <= 1) return x;

        int ans = 2;
        while(ans < x) {
            ans = ans*ans;
        }
        return ans;
    }
};

TEST(leetcode_69_sqrtx, leetcode_69_sqrtx_1)
{
    Solution s;
    int in2 = 26;
    int ans2 = 5;
    EXPECT_EQ(s.leetcode_69_sqrtx(in2), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
