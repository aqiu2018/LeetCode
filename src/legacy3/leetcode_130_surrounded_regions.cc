/**
 * 
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_row;
    int m_col;
    vector<vector<int>> m_index{{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x<0 || x>=m_row || y < 0 || y >= m_col || board[x][y] != 'O') return;
        board[x][y] = '1';

        for (auto p : m_index) dfs(board, x+p[0], y+p[1]);
    }
    void leetcode_130_surrounded_regions(vector<vector<char>>& board) {

        m_row = board.size();
        m_col = m_row == 0 ? 0 : board[0].size();

        for (int i = 0; i < m_row; ++i) {
            dfs(board, i, 0);
            dfs(board, i,  m_col-1);
        }

        for (int i = 1; i < m_col-1; ++i) {
            dfs(board, 0, i);
            dfs(board, m_row-1,  i);
        }

        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};

TEST(leetcode_130_surrounded_regions, leetcode_130_surrounded_regions_1)
{
    Solution s;
    vector<vector<char>> in3 = {
             {'X','X','X','X'},
             {'X','O','O','X'},
             {'X','X','O','X'},
             {'X','O','X','X'}
    };
    vector<vector<char>> ans2 = {
            {'X','X','X','X'},
            {'X','X','X','X'},
            {'X','X','X','X'},
            {'X','O','X','X'}
    };
    s.leetcode_130_surrounded_regions(in3);
    EXPECT_EQ(in3, ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
