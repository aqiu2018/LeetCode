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
    void leetcode_130_surrounded_regions(vector<vector<char>>& board) {
            int rowSize = board.size();
            if (rowSize == 0) return ;

            int colSize = board[0].size();
            for (int i = 0; i < rowSize; ++i) {
                dfs(board, i, 0);
                dfs(board, i, colSize-1);
            }
            for (int j = 0; j < colSize; ++j) {
                dfs(board, 0, j);
                dfs(board, rowSize - 1 , j);
            }

            for (int k = 0; k < rowSize; ++k) {
                for (int i = 0; i < colSize; ++i) {
                    if(board[k][i]=='o') board[k][i] = 'O';
                    else board[k][i] = 'X';
                }
            }

        }

private:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i>=0 && i < board.size() && j>=0 && j<board[0].size() && board[i][j] == 'O'){
            board[i][j] = 'o';
            dfs(board, i-1, j);
            dfs(board, i+1, j);
            dfs(board, i, j-1);
            dfs(board, i, j+1);
        }
    }
};

TEST(leetcode_130_surrounded_regions, leetcode_130_surrounded_regions_1)
{
    Solution s;
    vector<vector<char>> in;
    in.push_back(vector<char>({'X', 'X', 'X', 'X', 'X'}));
    in.push_back(vector<char>({'X', 'O', 'O', 'X', 'X'}));
    in.push_back(vector<char>({'X', 'X', 'O', 'X', 'X'}));
    in.push_back(vector<char>({'X', 'X', 'X', 'X', 'X'}));
    in.push_back(vector<char>({'X', 'X', 'O', 'X', 'X'}));

    vector<vector<char>> out;
    out.push_back(vector<char>({'X', 'X', 'X', 'X', 'X'}));
    out.push_back(vector<char>({'X', 'X', 'X', 'X', 'X'}));
    out.push_back(vector<char>({'X', 'X', 'X', 'X', 'X'}));
    out.push_back(vector<char>({'X', 'X', 'X', 'X', 'X'}));
    out.push_back(vector<char>({'X', 'X', 'O', 'X', 'X'}));


    bool ans = true;
    s.leetcode_130_surrounded_regions(in);
    EXPECT_EQ((in==out), ans);
}

TEST(leetcode_130_surrounded_regions, leetcode_130_surrounded_regions_2)
{
    Solution s;
    vector<vector<char>> in;
    in.push_back(vector<char>({'X'}));

    vector<vector<char>> out;
    out.push_back(vector<char>({'X'}));


    bool ans = true;
    s.leetcode_130_surrounded_regions(in);
    EXPECT_EQ((in==out), ans);
}


TEST(leetcode_130_surrounded_regions, leetcode_130_surrounded_regions_3)
{
    Solution s;
    vector<vector<char>> in;
    in.push_back(vector<char>({'O'}));

    vector<vector<char>> out;
    out.push_back(vector<char>({'O'}));


    bool ans = true;
    s.leetcode_130_surrounded_regions(in);
    EXPECT_EQ((in==out), ans);
}

TEST(leetcode_130_surrounded_regions, leetcode_130_surrounded_regions_4)
{
    Solution s;
    vector<vector<char>> in;
    in.push_back(vector<char>({'X', 'O', 'X', 'O', 'X', 'O'}));
    in.push_back(vector<char>({'O', 'X', 'O', 'X', 'O', 'X'}));
    in.push_back(vector<char>({'X', 'O', 'X', 'O', 'X', 'O'}));
    in.push_back(vector<char>({'O', 'X', 'O', 'X', 'O', 'X'}));

    vector<vector<char>> out;
    in.push_back(vector<char>({'X', 'O', 'X', 'O', 'X', 'O'}));
    in.push_back(vector<char>({'O', 'X', 'X', 'X', 'X', 'X'}));
    in.push_back(vector<char>({'X', 'X', 'X', 'X', 'X', 'O'}));
    in.push_back(vector<char>({'O', 'X', 'O', 'X', 'O', 'X'}));



    bool ans = true;
    s.leetcode_130_surrounded_regions(in);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << in[i][j];
        }
        cout << endl;
    }

    EXPECT_EQ((in==out), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
