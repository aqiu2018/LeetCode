/**
 * 
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_120_triangle(vector<vector<int>>& triangle) {

        int row = triangle.size();
        if(row == 0) return 0;
        int col = triangle[0].size();

        vector<int> dp(col);
        dp = triangle[row-1];

        for (int i = row-2; i >= 0; i--) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};

TEST(leetcode_120_triangle, leetcode_120_triangle_1)
{
    Solution s;
    vector<vector<int>> in = {
            {2, 0, 0, 0},
            {3, 4, 0, 0},
            {6, 5, 7, 0},
            {4, 1, 8, 3},
            };
    int ans = 11;

    EXPECT_EQ(s.leetcode_120_triangle(in), ans);
}

TEST(leetcode_120_triangle, leetcode_120_triangle_2)
{
    Solution s;
    vector<vector<int>> in = {
            {2, 0, 0, 0},
    };
    int ans = 2;

    EXPECT_EQ(s.leetcode_120_triangle(in), ans);
}

TEST(leetcode_120_triangle, leetcode_120_triangle_3)
{
    Solution s;
    vector<vector<int>> in = {
    };
    int ans = 0;

    EXPECT_EQ(s.leetcode_120_triangle(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
