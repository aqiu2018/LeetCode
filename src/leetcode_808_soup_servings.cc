/**
 *
有 A 和 B 两种类型的汤。一开始每种类型的汤有 N 毫升。有四种分配操作：

提供 100ml 的汤A 和 0ml 的汤B。
提供 75ml 的汤A 和 25ml 的汤B。
提供 50ml 的汤A 和 50ml 的汤B。
提供 25ml 的汤A 和 75ml 的汤B。
当我们把汤分配给某人之后，汤就没有了。每个回合，我们将从四种概率同为0.25的操作中进行分配选择。如果汤的剩余量不足以完成某次操作，我们将尽可能分配。当两种类型的汤都分配完时，停止操作。

注意不存在先分配100 ml汤B的操作。

需要返回的值： 汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2。

示例:
输入: N = 50
输出: 0.625
解释:
如果我们选择前两个操作，A将首先变为空。对于第三个操作，A和B会同时变为空。对于第四个操作，B将首先变为空。
所以A变为空的总概率加上A和B同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。

注释:
0 <= N <= 10^9。
返回值在 10^-6 的范围将被认为是正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/soup-servings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 **/

#include "headers.h"

class Solution
{
public:
    int M(int x) { return max(0, x); }

    double leetcode_808_soup_servings(int N) {
        N = N/25 + (N%25 > 0 ? 1 : 0);
        if (N >= 500) return 1.0;

        vector<vector<double>> memo;
        memo.resize(N+1);
        for (int k = 0; k < N+1; ++k) {
            memo[k].resize(N+1);
        }

        for (int s = 0; s <= 2*N; ++s) {
            for (int i = 0; i <= N; ++i) {
                int j = s-i;
                if (j < 0 || j > N) continue;
                double ans = 0.0;
                if (i == 0) ans = 1.0;
                if (i == 0 && j == 0) ans = 0.5;
                if (i > 0 && j > 0) {
                    ans = 0.25 * (memo[M(i-4)][j] + memo[M(i-3)][M(j-1)] +
                                  memo[M(i-2)][M(j-2)] + memo[M(i-1)][M(j-3)]);
                }
                memo[i][j] = ans;

            }
        }

        return memo[N][N];
    }

};

TEST(leetcode_808_soup_servings, leetcode_808_soup_servings_1)
{
    Solution s;
    int in = 50;
    double ans = 0.625;
    EXPECT_EQ(s.leetcode_808_soup_servings(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}