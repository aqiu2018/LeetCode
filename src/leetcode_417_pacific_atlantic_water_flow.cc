/**
 * 
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_row, m_col;
    vector<vector<int>> m_res;
    vector<vector<int>> dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& visited, int pre){

        if(x < 0 || x >= m_row || y < 0 || y >= m_col || visited[x][y] || matrix[x][y] < pre) return;

        visited[x][y] = true;
        for(auto &posi : dd){
            dfs(matrix, posi[0]+x, posi[1]+y, visited, matrix[x][y]);
        }
    }

    vector<vector<int>> leetcode_417_pacific_atlantic_water_flow(vector<vector<int>>& matrix) {

        if(matrix.empty()) return m_res;
        m_row = matrix.size();
        m_col = matrix.front().size();
        vector<vector<bool>> pacific(m_row, vector<bool>(m_col, false));
        vector<vector<bool>> atlantic(m_row, vector<bool>(m_col, false));

        for(int i = 0; i < m_row; i++) {
            dfs(matrix, i, 0, pacific, INT_MIN);
            dfs(matrix, i, m_col-1, atlantic, INT_MIN);
        }

        for(int i = 0; i < m_col; i++) {
            dfs(matrix, 0, i, pacific, INT_MIN);
            dfs(matrix, m_row-1, i, atlantic, INT_MIN);
        }

        for(int i = 0; i < m_row; i++) {
            for(int j = 0; j < m_col; j++) {
                if(pacific[i][j] && atlantic[i][j]) m_res.push_back({i, j});
            }
        }


        return m_res;
    }
};

TEST(leetcode_417_pacific_atlantic_water_flow, leetcode_417_pacific_atlantic_water_flow_1)
{
    Solution s;
    vector<vector<int>> in = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> ans={{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};

    EXPECT_EQ(s.leetcode_417_pacific_atlantic_water_flow(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
