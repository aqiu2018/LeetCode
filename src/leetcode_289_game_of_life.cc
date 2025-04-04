/**
 * 
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

 

示例：

输入：
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 

进阶：

你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/game-of-life
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void leetcode_289_game_of_life(vector<vector<int>>& board) {
        int row = board.size();
        int col = row ? board[0].size() : 0;
        if(col == 0) return;

        const int r = 1;
        std::vector<std::vector<int>> m_index = {
                {-r, -r}, {0, -r}, {r, -r}, {r, 0},
                {r, r}, {0, r}, {-r, r}, {-r, 0}
        };

        // 0 d -> d
        // 1 l -> l
        // 2 l -> d
        // 3 d -> l
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int zeroCnt = 0;
                int oneCnt = 0;
                for(auto index : m_index){
                    int x = i + index[0];
                    int y = j + index[1];
                    if(x<0 || y < 0 || x >= row || y >= col) continue;

                    if(board[x][y] == 1 || board[x][y] == 2) oneCnt++;
                    else zeroCnt++;
                }

                if(board[i][j] == 0 && oneCnt == 3) board[i][j] = 3;
                if(board[i][j] == 1 && oneCnt < 2 || board[i][j] == 1 && oneCnt > 3) board[i][j] = 2;
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};

TEST(leetcode_289_game_of_life, leetcode_289_game_of_life_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_289_game_of_life(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
