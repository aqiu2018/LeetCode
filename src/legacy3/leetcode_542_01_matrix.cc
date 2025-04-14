/**
 * 
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<int>> leetcode_542_01_matrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = row == 0 ? 0 : matrix[0].size();
        if (col == 0) return matrix;
        
        vector<vector<int>> dp(row+2, vector<int>(col+2, 0));
        for (int k = 0; k < row+2; ++k) {
            dp[k][0] = 10000;
            dp[k][col+1] = 10000;
        }
        for (int k = 0; k < col+2; ++k) {
            dp[0][k] = 10000;
            dp[row+1][k] = 10000;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] != 0) dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + 1;
            }
        }

        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (matrix[i][j] != 0) dp[i+1][j+1] = min(dp[i+1][j+1], min(dp[i+2][j+1], dp[i+1][j+2]) + 1);
                matrix[i][j] = dp[i+1][j+1];
            }
        }

        return matrix;
    }
};

TEST(leetcode_542_01_matrix, leetcode_542_01_matrix_3)
{
    Solution s;
    vector<vector<int>> in2 ={
            {1,1,0,0,1,0,0,1,1,0},
            {1,0,0,1,0,1,1,1,1,1},
            {1,1,1,0,0,1,1,1,1,0},
            {0,1,1,1,0,1,1,1,1,1},
            {0,0,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,0,1,1,1},
            {0,1,1,1,1,1,1,0,0,1},
            {1,1,1,1,1,0,0,1,1,1},
            {0,1,0,1,1,0,1,1,1,1},
            {1,1,1,0,1,0,1,1,1,1}
    };
    vector<vector<int>> ans = {
            {2,1,0,0,1,0,0,1,1,0},
            {1,0,0,1,0,1,1,2,2,1},
            {1,1,1,0,0,1,2,2,1,0},
            {0,1,2,1,0,1,2,3,2,1},
            {0,0,1,2,1,2,1,2,1,0},
            {1,1,2,3,2,1,0,1,1,1},
            {0,1,2,3,2,1,1,0,0,1},
            {1,2,1,2,1,0,0,1,1,2},
            {0,1,0,1,1,0,1,2,2,3},
            {1,2,1,0,1,0,1,2,3,4}
    };
    s.leetcode_542_01_matrix(in2);
    EXPECT_EQ(in2, ans);
}

TEST(leetcode_542_01_matrix, leetcode_542_01_matrix_2)
{
    Solution s;
    vector<vector<int>> in2 = {
            {0,0,0},
            {0,1,0},
            {1,1,1}
    };
    vector<vector<int>> ans = {
            {0,0,0},
            {0,1,0},
            {1,2,1}
    };
    s.leetcode_542_01_matrix(in2);
    EXPECT_EQ(in2, ans);
}

TEST(leetcode_542_01_matrix, leetcode_542_01_matrix_1)
{
    Solution s;
    vector<vector<int>> in2 = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
    };
    vector<vector<int>> ans = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
    };
    s.leetcode_542_01_matrix(in2);
    EXPECT_EQ(in2, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
