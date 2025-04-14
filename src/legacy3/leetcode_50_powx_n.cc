/**
 * 
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
输入: 2.00000, 10
输出: 1024.00000

示例 2:
输入: 2.10000, 3
输出: 9.26100

示例 3:
输入: 2.00000, -2
输出: 0.25000

 解释: 2-2 = 1/22 = 1/4 = 0.25

说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    double leetcode_50_powx_n(double x, int n)
    {
//        if (n == 0) return 1;
        if (x == 0) return 0;
        if (n < 0){
            x = 1 / x;
            n = -(n + 1);
            return func(x, n) * x;
        }

        return func(x, n);
    }

private:
    double func(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n%2 == 1) return pow(func(x, n/2), 2) * x;
        else return pow(func(x, n/2), 2);
    }

};

TEST(leetcode_50_powx_n, leetcode_50_powx_n_1)
{
    Solution s;
    double x = 2;
    int n = 10;
    double ans = 1024;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_2)
{
    Solution s;
    double x = 2.1;
    int n = 3;
    double ans = 2.1*2.1*2.1;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}


TEST(leetcode_50_powx_n, leetcode_50_powx_n_3)
{
    Solution s;
    double x = 2;
    int n = -2;
    double ans = 0.25;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_4)
{
    Solution s;
    double x = -1;
    int n = 2;
    double ans = 1;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_5)
{
    Solution s;
    double x = 0;
    int n = 2;
    double ans = 0;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_6)
{
    Solution s;
    double x = 1;
    int n = 2;
    double ans = 1;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_7)
{
    Solution s;
    double x = -1;
    int n = -2;
    double ans = 1;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_8)
{
    Solution s;
    double x = 8.95371;
    int n = -1;
    double ans = 1/8.95371;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

TEST(leetcode_50_powx_n, leetcode_50_powx_n_9)
{
    Solution s;
    double x = 1;
    int n = -2147483648;
    double ans = 1;
    EXPECT_EQ(s.leetcode_50_powx_n(x, n), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
