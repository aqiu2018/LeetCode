/**
 * 
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_col = 0;
    int m_row = 0;
    vector<vector<int>> m_index = {{-1,0},{0,-1},{0,1},{1,0}};
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int x, int y) {
        if (x < 0 || x >= m_row || y < 0 || y >= m_col || visited[x][y] || board[x][y] != word[index]) {
            return false;
        }

        visited[x][y] = true;
        if (index == word.size()-1) {
            return true;
        }

        for (auto p : m_index) {
            if(dfs(board, visited, word, index+1, x+p[0], y+p[1])) return true;
        }

        visited[x][y] = false;
        return false;
    }

    bool leetcode_79_word_search(vector<vector<char>>& board, string word) {

        m_row = board.size();
        m_col = board[0].size();
        if (word.size() > m_row*m_col) return false;

        vector<vector<bool>> visited(m_row, vector<bool>(m_col, false));
        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                if(board[i][j] == word[0] && dfs(board, visited, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
TEST(leetcode_79_word_search, leetcode_79_word_search_7)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'a','a','a','a'},
            {'a','a','a','a'},
            {'a','a','a','a'}
    };
    string word = "aaaaaaaaaaab";
    bool ans2 = false;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}

TEST(leetcode_79_word_search, leetcode_79_word_search_5)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'a','a','a','a'},
            {'a','a','a','a'},
            {'a','a','a','a'}
    };
    string word = "aaaaaaaaaaaaa";
    bool ans2 = false;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}

TEST(leetcode_79_word_search, leetcode_79_word_search_6)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'A','B','C','E'},
            {'S','F','E','S'},
            {'A','D','E','E'}
    };
    string word = "ABCESEEEFS";
    bool ans2 = true;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}

TEST(leetcode_79_word_search, leetcode_79_word_search_4)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'C','A','A'},
            {'A','A','A'},
            {'B','C','D'}
    };
    string word = "AAB";
    bool ans2 = true;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}

TEST(leetcode_79_word_search, leetcode_79_word_search_3)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word = "SEE";
    bool ans2 = true;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}
TEST(leetcode_79_word_search, leetcode_79_word_search_2)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word = "ABCB";
    bool ans2 = false;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}
TEST(leetcode_79_word_search, leetcode_79_word_search_1)
{
    Solution s;
    vector<vector<char>> in2 = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word = "ABCCED";
    bool ans2 = true;

    EXPECT_EQ(s.leetcode_79_word_search(in2, word), ans2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
