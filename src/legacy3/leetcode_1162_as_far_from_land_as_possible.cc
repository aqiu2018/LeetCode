/**
 * 
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。

示例 1：
输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。

 示例 2：
输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释：
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 
提示：
1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_1162_as_far_from_land_as_possible(vector<vector<int>>& grid) {

        int m_row = grid.size();
        if(m_row == 0) return 0;
        int m_col = grid[0].size();
        if(m_col == 0) return 0;

        long int ans = -1;
        vector<vector<long int> >  dp(m_row+2, vector<long int>(m_col+2, INT_MAX));

        int cnt = 0;
        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                if(grid[i][j] == 1) dp[i+1][j+1] = 0;
                else {
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j])+1;
                    cnt++;
                }
            }
        }
        if(cnt ==0 || cnt == m_row * m_col) return -1;

        for (int i = m_row-1; i >=0; i--) {
            for (int j = m_col-1; j >= 0; j--) {
                if(grid[i][j] == 1) dp[i+1][j+1] = 0;
                else dp[i+1][j+1] = min(min(dp[i+1][j+2], dp[i+2][j+1])+1, dp[i+1][j+1]);

                ans = max(ans, dp[i+1][j+1]);
            }
        }

        return ans;
    }
};

TEST(leetcode_1162_as_far_from_land_as_possible, leetcode_1162_as_far_from_land_as_possible_5)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,0,0},{0,0,0},{0,0,0}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_1162_as_far_from_land_as_possible(in2), ans);
}

TEST(leetcode_1162_as_far_from_land_as_possible, leetcode_1162_as_far_from_land_as_possible_4)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    int ans = 2;
    EXPECT_EQ(s.leetcode_1162_as_far_from_land_as_possible(in2), ans);
}

TEST(leetcode_1162_as_far_from_land_as_possible, leetcode_1162_as_far_from_land_as_possible_3)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,1,1},{1,1,1},{1,1,1}};
    int ans = -1;
    EXPECT_EQ(s.leetcode_1162_as_far_from_land_as_possible(in2), ans);
}
TEST(leetcode_1162_as_far_from_land_as_possible, leetcode_1162_as_far_from_land_as_possible_2)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{0,0,0},{0,0,0},{0,0,0}};
    int ans = -1;
    EXPECT_EQ(s.leetcode_1162_as_far_from_land_as_possible(in2), ans);
}

TEST(leetcode_1162_as_far_from_land_as_possible, leetcode_1162_as_far_from_land_as_possible_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,0,1},{0,0,0},{1,0,1}};
    int ans = 2;
    EXPECT_EQ(s.leetcode_1162_as_far_from_land_as_possible(in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
