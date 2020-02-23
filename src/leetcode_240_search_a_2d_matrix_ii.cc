/**
 *
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 **/

#include "headers.h"

class Solution
{
public:
    bool leetcode_240_search_a_2d_matrix_ii(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return  false;

        int row = matrix.size()-1, col = 0;
        while(row >= 0 && col < matrix[0].size()){
            if(matrix[row][col] > target) row--;
            else if (matrix[row][col] < target) col++;
            else return true;
        }

        return false;
    }
};

TEST(leetcode_240_search_a_2d_matrix_ii, leetcode_240_search_a_2d_matrix_ii_1)
{
    Solution s;
    vector<vector<int>> in = {  {1,   4,  7, 11, 15},
                                {2,   5,  8, 12, 19},
                                {3,   6,  9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_240_search_a_2d_matrix_ii(in, 5), ans);
}

TEST(leetcode_240_search_a_2d_matrix_ii, leetcode_240_search_a_2d_matrix_ii_2)
{
    Solution s;
    vector<vector<int>> in = {  {1,   4,  7, 11, 15},
                                {2,   5,  8, 12, 19},
                                {3,   6,  9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
    bool ans = false;
    EXPECT_EQ(s.leetcode_240_search_a_2d_matrix_ii(in, 20), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}