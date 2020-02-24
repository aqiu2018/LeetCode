/**
 * 
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:
输入:
11110
11010
11000
00000

输出: 1


示例 2:
输入:
11000
11000
00100
00011

输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

#include "headers.h"

class Solution
{
public:

    int Find(int p){
        while(p != m_rst[p]) p = m_rst[p];
        return p;
    }

    int convert(int i, int j)
    {
        int ret = -1;
        if(i>=0 && j>= 0 && (m_rst[i* m_col + j] != -1)) ret = Find(i* m_col + j);

        return ret;
    }

    int unions(int i, int j){

        int ret = i*m_col + j;
        int left = convert(i, j - 1); // parents
        int up = convert(i - 1, j);

        if (left >= 0 && up >= 0) {
            if (left == up)
                return left;
            else{
                m_rst[left] = up;
                m_count --;
                return ((i-1)*m_col + j);
            }
        }
        else if(left >= 0){
            return (i * m_col + j -1);
        }
        else if(up >= 0){
            return ((i-1)*m_col + j);
        }

        m_count ++;
        return ret;
    }

    int leetcode_200_number_of_islands(vector<vector<char>>& grid)
    {

        m_row = grid.size();
        if(m_row == 0) return 0;

        m_col = grid[0].size();
        for (int k = 0; k < m_col * m_row; ++k) {
            m_rst[k] = -1;
        }


        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                if(grid[i][j] == '1'){
                    int p = i * m_col + j;
                    m_rst[p] = unions(i, j);
                }
            }
        }


        return m_count;
    }

    unordered_map<int, int> m_rst;
    int m_col = 0;
    int m_row = 0;
    int m_count = 0;
};

TEST(leetcode_200_number_of_islands, leetcode_200_number_of_islands_1)
{
    Solution s;
    vector<vector<char>> in;
    in.push_back(vector<char>({'1', '1', '0', '0', '0'}));
    in.push_back(vector<char>({'1', '1', '0', '0', '0'}));
    in.push_back(vector<char>({'0', '0', '1', '0', '0'}));
    in.push_back(vector<char>({'0', '0', '0', '1', '1'}));
    in.push_back(vector<char>({'0', '0', '0', '1', '1'}));
    in.push_back(vector<char>({'0', '0', '0', '1', '1'}));
    int ans = 3;
    EXPECT_EQ(s.leetcode_200_number_of_islands(in), ans);
}

TEST(leetcode_200_number_of_islands, leetcode_200_number_of_islands_2)
{
    Solution s;
    vector<vector<char>> in;
    in.push_back(vector<char>({'1', '1', '1', '1', '0'}));
    in.push_back(vector<char>({'1', '1', '0', '1', '0'}));
    in.push_back(vector<char>({'1', '1', '0', '0', '0'}));
    in.push_back(vector<char>({'1', '1', '0', '0', '0'}));
    in.push_back(vector<char>({'0', '0', '0', '0', '0'}));

    int ans = 1;
    EXPECT_EQ(s.leetcode_200_number_of_islands(in), ans);
}

TEST(leetcode_200_number_of_islands, leetcode_200_number_of_islands_3)
{
    Solution s;
    vector<vector<char>> in;
    int ans = 0;
    EXPECT_EQ(s.leetcode_200_number_of_islands(in), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
