/**
 * 
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_row, m_col;
    vector<vector<int>> dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int leetcode_994_rotting_oranges(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        m_row = grid.size();
        m_col = grid.front().size();
        queue<pair<int, int>> pStack;
        int goodCnt = 0;

        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                if (grid[i][j] == 2) pStack.push({i, j});
                else if(grid[i][j]==1) goodCnt++;
            }
        }

        int ans = 0;
        while (!pStack.empty()){
            pair<int, int> temp = pStack.front();
            pStack.pop();
            for(auto &posi : dd){
                int dx = posi[0]+temp.first;
                int dy = posi[1]+temp.second;

                if(dx < 0 || dx >= m_row || dy < 0 || dy >= m_col || grid[dx][dy] != 1) continue;

                grid[dx][dy] = grid[temp.first][temp.second]+1;
                goodCnt--;
                pStack.push({dx, dy});
                ans = grid[dx][dy] - 2;
//                ans = max(ans, grid[dx][dy] - 2);
                cout << "x " << temp.first << " y " << temp.second\
                << " dx " << dx << " dy " << dy<< " ans " << ans << endl;
            }
        }

        return goodCnt == 0 ? ans : -1;
    }
};

TEST(leetcode_994_rotting_oranges, leetcode_994_rotting_oranges_1)
{
    Solution s;
    vector<vector<int>> in = {{2,1,1},{1,1,0},{0,1,1}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_994_rotting_oranges(in), ans);
}

TEST(leetcode_994_rotting_oranges, leetcode_994_rotting_oranges_2)
{
    Solution s;
    vector<vector<int>> in = {{2},{1},{1},{1},{2},{1},{1}};
    int ans = 2;
    EXPECT_EQ(s.leetcode_994_rotting_oranges(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
