/**
 * 
n-queens
 n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * 
 */
#include "headers.h"

class Solution
{
private:
    vector<vector<string>> m_res;
    vector<bool> m_col, m_diagonal1, m_diagonal2;

    // n queen, 在index行的位置
    void putQueen(int n, int index, vector<int> &row){

        if( index == n ){
            m_res.push_back(generateBoard(n, row));
            return;
        }

        for (int i = 0; i < n; ++i) {
            if(!m_col[i] && !m_diagonal1[index + i] && !m_diagonal2[index - i + n - 1]){
                row.push_back(i);
                m_col[i] = true;
                m_diagonal1[index + i] = true;
                m_diagonal2[index - i + n - 1]= true;

                putQueen(n, index+1, row);

                m_col[i] = false;
                m_diagonal1[index + i] = false;
                m_diagonal2[index - i + n - 1]= false;
                row.pop_back();

            }
        }

        return;
    }

    vector<string> generateBoard(int n, vector<int> &row){
        assert( row.size() == n);
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][row[i]] = 'Q';
        }
        return board;
    }

public:
    vector<vector<string>> leetcode_51_n_queens(int n) {
//    vector<vector<string>> solveNQueens(int n) {
        m_res.clear();

        m_col = vector<bool>(n, false);
        m_diagonal1 = vector<bool>(2 * n - 1, false);
        m_diagonal2 = vector<bool>(2 * n - 1, false);

        vector<int> row;
        putQueen(n, 0, row);

        return m_res;
    }
};

TEST(leetcode_51_n_queens, leetcode_51_n_queens_1)
{
    Solution s;
    int in = 4;
    vector<vector<string>>  ans =
        {
            {".Q..",  // 解法 1
            "...Q",
            "Q...",
            "..Q."},

            {"..Q.",  // 解法 2
            "Q...",
            "...Q",
            ".Q.."}
        };
    EXPECT_EQ(s.leetcode_51_n_queens(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
