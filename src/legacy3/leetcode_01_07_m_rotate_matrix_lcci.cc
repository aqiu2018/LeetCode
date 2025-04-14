/**
 * 
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-matrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void leetcode_01_07_m_rotate_matrix_lcci(vector<vector<int>>& matrix) {

        int n = matrix.size();
        if(n==0) return;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }

    }
};
TEST(leetcode_01_07_m_rotate_matrix_lcci, leetcode_01_07_m_rotate_matrix_lcci_2)
{
    Solution s;
    vector<vector<int>>  in1 = {
            { 5, 1, 9,11},
            { 2, 4, 8,10},
            {13, 3, 6, 7},
            {15,14,12,16}
    };
    vector<vector<int>>  ans = {
            {15,13, 2, 5},
            {14, 3, 4, 1},
            {12, 6, 8, 9},
            {16, 7,10,11}
    };
    s.leetcode_01_07_m_rotate_matrix_lcci(in1);
    EXPECT_EQ(in1, ans);
}

TEST(leetcode_01_07_m_rotate_matrix_lcci, leetcode_01_07_m_rotate_matrix_lcci_1)
{
    Solution s;
    vector<vector<int>>  in1 = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    vector<vector<int>>  ans = {
            {7,4,1},
            {8,5,2},
            {9,6,3}
    };
    s.leetcode_01_07_m_rotate_matrix_lcci(in1);
    EXPECT_EQ(in1, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
