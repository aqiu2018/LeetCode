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
    double helper(double x, long long n) {
        if (n == 0) return 1.0;

        double mid = helper(x, n/2);
        return n % 2 == 0 ? mid * mid : mid * mid * x;
    }
    double leetcode_50_powx_n_by_leetcode_solution(double x, int n) {
        long long N = n;
        return (N >= 0) ? helper(x, N) : 1.0 / helper(x, -N);
    }
};

TEST(leetcode_50_powx_n_by_leetcode_solution, leetcode_50_powx_n_by_leetcode_solution_1)
{
    Solution s;
    double ans2 = 9.26100;
    EXPECT_EQ(s.leetcode_50_powx_n_by_leetcode_solution(2.10000, 3), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
