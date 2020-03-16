/**
 * 
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int mRow;
    int mCol;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i > mRow -1 || j < 0 || j > mCol-1 || grid[i][j]==0) return 0;
        grid[i][j]=0;

        return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    int leetcode_695_max_area_of_island(vector<vector<int>>& grid) {

        mRow = grid.size();
        if(mRow == 0) return 0;
        mCol = grid[0].size();
        int ans = 0;

        for (int i = 0; i < mRow; ++i) {
            for (int j = 0; j < mCol; ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;
    }
};
TEST(leetcode_695_max_area_of_island, leetcode_695_max_area_of_island_2)
{
    Solution s;
    vector<vector<int>> in1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0},
                               {0,1,1,0,1,0,0,0,0,0,0,0,0},
                               {0,1,0,0,1,1,0,0,1,0,1,0,0},
                               {0,1,0,0,1,1,0,0,1,1,1,0,0},
                               {0,0,0,0,0,0,0,0,0,0,1,0,0},
                               {0,0,0,0,0,0,0,1,1,1,0,0,0},
                               {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int ans = 6;
    EXPECT_EQ(s.leetcode_695_max_area_of_island(in1), ans);
}


TEST(leetcode_695_max_area_of_island, leetcode_695_max_area_of_island_1)
{
    Solution s;
    vector<vector<int>> in1 = {{0,0,0,0}};
    int ans = 0;
    EXPECT_EQ(s.leetcode_695_max_area_of_island(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
